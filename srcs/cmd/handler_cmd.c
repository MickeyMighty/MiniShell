/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 04:46:01 by loamar            #+#    #+#             */
/*   Updated: 2021/01/11 18:54:12 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static 	int 	get_args(t_msh *msh, t_list *element)
{
	int 	pos;

	pos = 1;
	if (element->token == CMD)
	{
		if (element->next->token == ARGS)
		{
			tmp = element;
			element = element->next;
			while (element->token == ARGS)
			{
				element = element->next;
				msh->utils->size_args++;
			}
			element = tmp;
			if (!(msh->utils->tab_args = malloc(sizeof(char *) * msh->utils->size_args + 1)))
				return (0);
			while (element->token == ARGS)
			{
				msh->utils->tab_args[pos] = element->content;
				pos++;
				element = element->next; // a refaire la meme mais pour remplir le tableau d arg;
			}
			return (1);
		}
	}
	else
		return (0);
}

int 			handler_cmd(t_msh *msh, char **env)
{
	t_list 	*element;
	t_list	*tmp;

	msh->utils->size_args = 0;
	element = msh->lair_list->start;
	while (element != NULL)
	{
		get_args(msh, element);
		exec_cmd(msh, element, env);
		element = element->next;
	}
	exit(0);
}
