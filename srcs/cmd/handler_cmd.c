/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:33 by loamar            #+#    #+#             */
/*   Updated: 2021/03/01 14:58:42 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	get_value_sep(char *str)
{
	if (ft_strcmp(str, "|") == 0)
		return (PIPE);
	else if (ft_strcmp(str, "<") == 0 || ft_strcmp(str, ">") == 0
	|| ft_strcmp(str, ">>") == 0)
		return (REDIR);
	else if (ft_strcmp(str, ";") == 0)
		return (SEMICOLON);
	else
		return (0);
}

static t_list 	*multi_pipe(t_msh *msh, t_list *element, char **env)
{
	int		fd;

	msh->utils->multi_pipe = 0;
	// element = element->next;
	fd = dup(0);
	while (element
	&& element->next && (get_value_sep(element->next->content) == PIPE))
	{
		if (element->next->next->next
		&& get_value_sep(element->next->next->next->content) == PIPE)
				msh->utils->multi_pipe = 1;
		if (element->next->next != NULL)
			fd = ft_pipe(msh, element, env, fd);
		else
			handler_error(msh, "Bad syntaxe with the pipe.\n");
		if (msh->utils->multi_pipe == 1)
			element = element->next->next;
		else
			element = element->next->next->next;
		msh->utils->multi_pipe = 0;
	}
	close(fd);
	return (element);
}

int 	sort_cmd(t_msh *msh, t_list *element, char **env)
{
	t_list	*tmp;

	if (element->token != CMD)
		handler_error(msh, "WTFFFFF\n");
	while (element != NULL)
	{
		// element = handler_builtins(msh, element, env);
		if (element->next != NULL && element->next->token == SEPARATOR)
		{
			if (get_value_sep(element->next->content) == PIPE)
				element = multi_pipe(msh, element, env);
			// else if (get_value_sep(element->next->content) == REDIR)
				// element = ft_reddirection(msh, element);
			// else if (get_value_sep(element->content) == SEMICOLON)
			// 	;
		}
		else
			exec_cmd(msh, element, env);
		if (element != NULL)
			element = element->next;
	}
	// printf("element = %s\n", element->content);
	return (1);
}

int 	handler_cmd(t_msh *msh, char **env)
{
	// int id;
	int		ret;
	t_list 	*tmp;
	t_list 	*element;

	element = msh->lair_list->start;
	// id = fork();
	// if (id < 0)
		// handler_error(msh);
	msh->utils->check_sep = 0; // supp?
	// msh->utils->pid = fork();
	sort_cmd(msh, element, env);
	return (0);
}
