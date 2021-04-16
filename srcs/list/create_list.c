/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 04:25:27 by loamar            #+#    #+#             */
/*   Updated: 2021/04/16 13:23:47 by loamar           ###   ########.fr       */
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

static	int		is_empty_list(t_lair_list *lair_list)
{
	if (lair_list->size == 0)
	{
		free(lair_list);
		return (SUCCESS);
	}
	return (ERROR);
}

static	void	free_popback_list(t_list *temp)
{
	if (temp->content)
		free(temp->content);
	if (temp->tab_args)
		free_tab_args(temp->tab_args);
	free(temp);
}

int				pop_back_list(t_lair_list *lair_list)
{
	t_list		*temp;

	if (is_empty_list(lair_list) == SUCCESS)
		return (ERROR);
	if (lair_list->size == 1)
	{
		temp = lair_list->start;
		lair_list->start = lair_list->start->next;
		if (lair_list->start == NULL)
			lair_list->end = NULL;
		else
			lair_list->start->previous = NULL;
	}
	else
	{
		temp = lair_list->end;
		lair_list->end->previous->next = NULL;
		lair_list->end = lair_list->end->previous;
	}
	free_popback_list(temp);
	lair_list->size--;
	return (SUCCESS);
}
