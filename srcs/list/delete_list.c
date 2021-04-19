/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:38:22 by loamar            #+#    #+#             */
/*   Updated: 2021/04/19 12:29:26 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

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

static	t_list 	*pop_pos_list(t_lair_list *lair_list, t_list *temp, int pos)
{
		int			target;
		t_list		*courant;

		courant = NULL;
		courant = lair_list->start;
		target = 1;
		while (target < pos)
		{
			courant = courant->next;
			target++;
		}
		temp = courant;
		courant->previous->next = courant->next;
		courant->next->previous = courant->previous;
		return (temp);
}

int				pop_choose_list(t_lair_list *lair_list, int pos)
{
	t_list		*temp;

	temp = NULL;
	if (is_empty_list(lair_list) == SUCCESS)
		return (ERROR);
	if (pos == 1)
	{
		temp = lair_list->start;
		lair_list->start = lair_list->start->next;
		if (lair_list->start == NULL)
			lair_list->end = NULL;
		else
			lair_list->start->previous = NULL;
	}
	else if (pos == lair_list->size)
	{
		temp = lair_list->end;
		lair_list->end->previous->next = NULL;
		lair_list->end = lair_list->end->previous;
	}
	else
		temp = pop_pos_list(lair_list, temp, pos);
	free_popback_list(temp);
	lair_list->size--;
	return (SUCCESS);
}
