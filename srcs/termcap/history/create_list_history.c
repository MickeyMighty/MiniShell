/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_history.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 02:33:35 by loamar            #+#    #+#             */
/*   Updated: 2021/04/29 14:50:27 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

int				ft_fill_empty_history(t_history_lair *history_lair, char *content)
{
	t_history_list	*new_element;

	if (!(new_element = (t_history_list *)malloc(sizeof(t_list))))
		return (-1);
	new_element->content = content;
	new_element->previous = history_lair->start;
	new_element->next = history_lair->end;
	history_lair->end = new_element;
	history_lair->start = new_element;
	history_lair->size++;
	return (0);
}

int				ft_fill_start_history(t_history_lair *history_lair, char *content)
{
	t_history_list	*new_element;

	if (!(new_element = (t_history_list *)malloc(sizeof(t_history_list))))
		return (-1);
	new_element->content = content;
	new_element->previous = NULL;
	new_element->next = history_lair->start;
	history_lair->start->previous = new_element;
	history_lair->start = new_element;
	history_lair->size++;
	return (0);
}

int				clear_history(t_history_lair *history_lair)
{
	int		loop;

	loop = 0;
	while (loop == 0)
	{
		if (pop_back_history(history_lair) == ERROR)
			loop = 1;
	}
	return (SUCCESS);
}
