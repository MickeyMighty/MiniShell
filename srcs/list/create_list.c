/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 04:25:27 by loamar            #+#    #+#             */
/*   Updated: 2021/03/31 09:21:21 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int			ft_fill_empty_list(t_lair_list *lair_list, char *content)
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

int			ft_fill_end_list(t_lair_list *lair_list, char *content)
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

static	int	is_empty_list(t_lair_list *lair_list)
{
	if (lair_list == NULL)
		return (1);
	return (-1);
}

t_lair_list	*clear_list(t_lair_list *lair_list)
{
	while (!is_empty_list(lair_list))
		lair_list = pop_back_list(lair_list);
	return (NULL);
}

t_lair_list	*pop_back_list(t_lair_list *lair_list)
{
	t_list		*temp;

	if (is_empty_list(lair_list))
		return (NULL);
	if (lair_list->start == lair_list->end)
	{
		if (lair_list->start->content)
			free(lair_list->start->content);
		if (lair_list->start->tab_args)
			free_split(lair_list->start->tab_args);
		free(lair_list);
		lair_list = NULL;
		return (NULL);
	}
	temp = lair_list->end;
	lair_list->end->next = NULL;
	temp->next = NULL;
	temp->previous = NULL;
	if (temp->content)
		free(temp->content);
	if (temp->tab_args)
		free_split(temp->tab_args);
	// 	free(temp->tab_args);
	free(temp);
	lair_list->size--;
	return (lair_list);
}
