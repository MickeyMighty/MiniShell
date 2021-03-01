/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:33 by loamar            #+#    #+#             */
/*   Updated: 2021/03/01 17:24:50 by loamar           ###   ########.fr       */
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
	int		backup_fd;

	msh->utils->multi_pipe = 0;
	// element = element->next;
	backup_fd = 0;
	// backup_fd = dup2(backup_fd, 0);
	printf("ok\n");
	while (element != NULL)
	{
		printf("ok 1\n");
		printf("element = %s\n", element->content);
		if ((element->next != NULL
		|| (get_value_sep(element->next->content) == PIPE))
		|| (element->previous != NULL
		&& (get_value_sep(element->next->content) == PIPE)))
		{
			printf("ok cardano\n");
			backup_fd = ft_pipe(msh, element, env, backup_fd);
		}
		// if (element->next && (get_value_sep(element->next->content) == PIPE))
		else
		{
			printf("ok cardapute\n");
			close(backup_fd);
			return (element);
		}
		printf("ok 2\n");
		// if (element->next->next == NULL)
		// 	handler_error(msh, "Bad syntaxe with the pipe.\n");
		// else
		element = element->next->next;
		printf("ok 4\n");
	}
	printf("ok 5\n");
	close(backup_fd);
	printf("ok 6\n");
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
