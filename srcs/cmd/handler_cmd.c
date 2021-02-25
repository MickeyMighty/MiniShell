/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:33 by loamar            #+#    #+#             */
/*   Updated: 2021/02/25 15:51:59 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	multi_pipe(t_msh *msh, t_list *element, char **env, int next_step)
{
	if (element->token == PIPE)
	{
		while (element && (element->token == PIPE))
		{
			ft_pipe(msh, element, env);
			if (element->next->next
			&& (element->next->next->token == PIPE))
				element = element->next->next;
			else
				element = element->next;
		}
		while (element != NULL
		&& (element->token == PIPE || element->token == CMD))
		{
			element = element->next;
			next_step++;
		}
		return (next_step);
	}
	return (0);
}

int 	sort_cmd(t_msh *msh, t_list *element, char **env, int ret)
{
	int 	next_step;
	t_list	*tmp;

	next_step = 0;
	if (element->next && element->token == CMD)
	{
		if (element->token == PIPE)
			next_step = multi_pipe(msh, element, env, next_step);
		else if (element->token == REDIR)
		{
			// ft_reddirection(msh, element);
			next_step = 2;
		}
		if (element->token == SEMICOLON)
		{
			exec_cmd(msh, element->previous, env);
			next_step = 2;
		}
	}
	else if (!element->next)
		exec_cmd(msh, element, env);
	return (next_step);
}

int 	handler_cmd(t_msh *msh, char **env)
{
	// int id;
	int		ret;
	t_list 	*element;
	t_list 	*tmp;

	// id = fork();
	// if (id < 0)
		// handler_error(msh);
	element = msh->lair_list->start;
	msh->utils->check_sep = 0;
	// msh->utils->pid = fork();
	while (element != NULL)
	{
		ret = sort_cmd(msh, element, env, ret);
		while (ret != 0)
			element = element->next;
	}
	return (0);
}
