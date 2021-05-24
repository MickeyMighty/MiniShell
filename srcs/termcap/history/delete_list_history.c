/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_list_history.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 02:34:50 by loamar            #+#    #+#             */
/*   Updated: 2021/04/29 14:50:22 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

static	int		is_empty_history(t_history_lair *history_lair)
{
	if (history_lair->size == 0)
	{
		free(history_lair);
		return (SUCCESS);
	}
	return (ERROR);
}

static	void	free_popback_history(t_history_list *temp)
{
	if (temp->content)
		free(temp->content);
	free(temp);
}

int				pop_back_history(t_history_lair *history_lair)
{
	t_history_list		*temp;

	if (is_empty_history(history_lair) == SUCCESS)
		return (ERROR);
	if (history_lair->size == 1)
	{
		temp = history_lair->start;
		history_lair->start = history_lair->start->next;
		if (history_lair->start == NULL)
			history_lair->end = NULL;
		else
			history_lair->start->previous = NULL;
	}
	else
	{
		temp = history_lair->end;
		history_lair->end->previous->next = NULL;
		history_lair->end = history_lair->end->previous;
	}
	free_popback_history(temp);
	history_lair->size--;
	return (SUCCESS);
}
