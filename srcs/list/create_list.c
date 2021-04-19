/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 04:25:27 by loamar            #+#    #+#             */
/*   Updated: 2021/04/19 12:12:48 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int				ft_fill_empty_list(t_lair_list *lair_list, char *content)
{
	t_list	*new_element;

	if (!(new_element = (t_list *)malloc(sizeof(t_list))))
		return (-1);
	new_element->content = content;
	new_element->token = 0;
	new_element->tab_args = NULL;
	new_element->previous = lair_list->start;
	new_element->next = lair_list->end;
	lair_list->end = new_element;
	lair_list->start = new_element;
	lair_list->size++;
	return (0);
}

int				ft_fill_end_list(t_lair_list *lair_list, char *content)
{
	t_list	*new_element;

	if (!(new_element = (t_list *)malloc(sizeof(t_list))))
		return (-1);
	new_element->content = content;
	new_element->token = 0;
	new_element->tab_args = NULL;
	new_element->previous = lair_list->end;
	new_element->next = NULL;
	lair_list->end->next = new_element;
	lair_list->end = new_element;
	lair_list->size++;
	return (0);
}

int				clear_list(t_lair_list *lair_list)
{
	int		loop;

	loop = 0;
	while (loop == 0)
	{
		if (pop_back_list(lair_list) == ERROR)
			loop = 1;
	}
	return (SUCCESS);
}

static	t_list		*free_empty(t_msh *msh, t_list *element)
{
	char	*check;

	check = NULL;
	check = return_all_content(msh, element->content, 1);
	if (ft_strcmp(check, "\0") == 0)
	{
		free(check);
		pop_choose_list(msh->lair_list, msh->utils->i);
		if (msh->lair_list->size == 0)
			return (0);
		if (element->next)
			element = element->next;
		set_token_list(msh);
		return (element);
	}
	else
	{
		if (element->next)
			element = element->next;
		msh->utils->i++;
		free(check);
		return (element);
	}
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
		}
		else
		{
			element = element->next;
			msh->utils->i++;
		}
	}
}
