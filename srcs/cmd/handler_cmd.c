/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:33 by loamar            #+#    #+#             */
/*   Updated: 2021/02/27 11:36:56 by loamar           ###   ########.fr       */
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
	// printf("element->content = %s\n", element->content);
	element = element->next;
	while (element && (get_value_sep(element->content) == PIPE))
	{
		if (element->next != NULL)
			ft_pipe(msh, element, env);
		else
			handler_error(msh); // msg ??
		// printf("element->previous->content = %s\n", element->previous->content);
		// printf("element->content = %s\n", element->content);
		// printf("element->next->content = %s\n", element->next->content);
		if (element->next->next
		&& get_value_sep(element->next->next->content) == PIPE)
		{
			if (!element->next->next->next
			|| element->next->next->next->token != CMD)
				handler_error(msh); // msg ??
			else
				element = element->next->next;
		}
		else
			element = element->next;
		}
	return (element);
}

int 	sort_cmd(t_msh *msh, t_list *element, char **env)
{
	t_list	*tmp;

	if (element->token != CMD)
		handler_error(msh);
	while (element != NULL)
	{
		element = handler_builtins(msh, element, env);
		if (element->next != NULL && element->next->token == SEPARATOR)
		{
			if (get_value_sep(element->next->content) == PIPE)
				element = multi_pipe(msh, element, env);
			// else if (get_value_sep(element->next->content) == REDIR)
				// element = ft_reddirection(msh, element);
			// else if (get_value_sep(element->next->content) == SEMICOLON)
			// 	exec_cmd(msh, element->previous, env);
		}
		else
			exec_cmd(msh, element, env);
		printf("element = %s\n", element->content);
		if (element != NULL)
			element = element->next;
	}
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
