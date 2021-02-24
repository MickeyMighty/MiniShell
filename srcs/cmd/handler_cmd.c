/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:33 by loamar            #+#    #+#             */
/*   Updated: 2021/02/24 12:36:23 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	sort_cmd(t_msh *msh, t_list *element, char **env, int ret)
{
	int 	next_step;

	next_step = 0;
	if (element->next)
	{
		if (element->token == CMD && element->next->token == SEMICOLON)
		{
			exec_cmd(msh, element, env);
			next_step = 2;
		}
		else if (ret == PIPE)
		{
			while (element->token == PIPE) // a finir
			ft_pipe(msh, element);
			next_step = 2;
		}
		else if (ret == REDIR)
		{
			ft_reddirection(msh, element);
			next_step = 2;
		}
	}
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
