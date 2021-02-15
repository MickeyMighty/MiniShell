/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:33 by loamar            #+#    #+#             */
/*   Updated: 2021/02/15 15:40:15 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	handler_sep(t_msh *msh, t_list *element)
{
	element = element->next;
	if (element->token == SEPARATOR)
	{
		if (element->content == "|")
			return (ft_pipe(msh, element));
		if else (element->content == "<" || element->content == ">"
		|| element->content == ">>")
			return (ft_redirection(msh, element));
		if else (element->content == ";")
			return (ft_semicolon(msh,element));
	}
    return (0);
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
		if (element->next)
			ret = handler_sep(msh, env);
		handler_exec_cmd(msh, element);
	}
	return (0);
}
