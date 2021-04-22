/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_empty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:50:04 by loamar            #+#    #+#             */
/*   Updated: 2021/04/19 12:55:14 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static	t_list	*return_no_empty(t_msh *msh, t_list *element, char *check)
{
	if (element)
		element = element->next;
	msh->utils->i++;
	free(check);
	return (element);
}

static	t_list	*free_empty(t_msh *msh, t_list *element)
{
	char	*check;
	t_list	*index;
	int		limite;

	limite = 1;
	check = NULL;
	check = return_all_content(msh, element->content, 1);
	if (ft_strcmp(check, "\0") == 0)
	{
		free(check);
		pop_choose_list(msh->lair_list, msh->utils->i);
		if (msh->lair_list->size == 0)
			return (0);
		index = msh->lair_list->start;
		while (limite < msh->utils->i)
		{
			index = index->next;
			limite++;
		}
		set_token_list(msh);
		return (index);
	}
	else
		return (return_no_empty(msh, element, check));
}

static	t_list	*if_empty(t_msh *msh, t_list *element)
{
	if ((element->next
	&& (get_value_sep(element->next->content) == PIPE))
	|| ((msh->utils->i > 1)
	&& (get_value_sep(element->previous->content) == PIPE)
	&& (!element->next || element->next->token == SEPARATOR)))
	{
		msh->utils->i++;
		element = element->next;
	}
	else
		element = free_empty(msh, element);
	return (element);
}

void			check_empty(t_msh *msh)
{
	t_list	*element;

	msh->utils->i = 1;
	msh->utils->no_space = 0;
	element = msh->lair_list->start;
	while (element)
	{
		if ((element->token == CMD || element->token == ARGS
		|| element->token == OPTION) && element->content[0] == '$')
			element = if_empty(msh, element);
		else
		{
			element = element->next;
			msh->utils->i++;
		}
	}
}
