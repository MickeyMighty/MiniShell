/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:33 by loamar            #+#    #+#             */
/*   Updated: 2021/02/26 16:11:39 by loamar           ###   ########.fr       */
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
	printf("0\n");
	printf("element->content = %s\n", element->content);
	element = element->next;
	printf("0-2\n");
	while (element && (get_value_sep(element->content) == PIPE))
	{
		printf("1\n");
		if (element->next != NULL || element->next->content != NULL)
			ft_pipe(msh, element, env);
		else
			handler_error(msh); // msg ??
		printf("2\n");
		printf("element->previous->content = %s\n", element->previous->content);
		printf("element->content = %s\n", element->content);
		printf("element->next->content = %s\n", element->next->content);
		printf("element->next->next->content = %s\n", element->next->next->content);
		if (element->next->next->next == NULL)
			printf("MAIS NIKTAMERE\n");
		if (element->next->next != NULL)
		{
			printf("3 test\n");
			if (element->next->next
			&& get_value_sep(element->next->next->content) == PIPE
			&& (element->next->next->next == NULL
			|| element->next->next->next->token != CMD))
				handler_error(msh); // write a message arg 2
			else if (element->next->next
			&& (get_value_sep(element->next->next->content) == PIPE))
				element = element->next->next;
		}
		else
			element = element->next;
		printf("3\n");
	}
	while (element != NULL
	&& (get_value_sep(element->content) == PIPE || element->token == CMD))
		element = element->next;
		printf("4\n");
	return (element);
}

int 	sort_cmd(t_msh *msh, t_list *element, char **env)
{
	t_list	*tmp;

	printf ("check\n");
	if (element->token != CMD)
		handler_error(msh);
	if (ft_strcmp(element->content, "exit") == 0)
		exit(0);
	while (element != NULL)
	{
		if (element->next != NULL && element->next->token == SEPARATOR)
		{
			printf ("check 2\n");
			if (get_value_sep(element->next->content) == PIPE)
			{
				printf("PIPE\n");
				element = multi_pipe(msh, element, env);
			}
			else if (get_value_sep(element->next->content) == REDIR)
				// element = ft_reddirection(msh, element);
			printf ("check 3\n");
			else if (get_value_sep(element->next->content) == SEMICOLON)
			{
				exec_cmd(msh, element->previous, env);
			}
		}
		else
		{
			printf ("check 4\n");
			exec_cmd(msh, element, env);
		}
		element = element->next;
	}
	return (1);
	printf ("check 5\n");
}

int 	handler_cmd(t_msh *msh, char **env)
{
	// int id;
	int		ret;
	t_list 	*tmp;
	t_list 	*element;

	element = msh->lair_list->start;
	if (ft_strcmp(element->content, "exit") == 0)
		exit(0);
	// id = fork();
	// if (id < 0)
		// handler_error(msh);
	msh->utils->check_sep = 0; // supp?
	// msh->utils->pid = fork();
	sort_cmd(msh, element, env);
	return (0);
}
