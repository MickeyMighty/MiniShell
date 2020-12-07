/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_list_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 04:25:27 by loamar            #+#    #+#             */
/*   Updated: 2020/12/07 17:24:29 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	ft_fill_empty_list(t_lair_list *lair_list, char *content, t_prompt_list *new_element)
{
	// t_prompt_list	*new_element;

	// if (!(new_element = (t_prompt_list *)malloc(sizeof(t_prompt_list))))
	// 	return (-1);
	new_element->content = content;
	new_element->previous = lair_list->start;
	new_element->next = lair_list->end;
	lair_list->start = new_element;
	lair_list->end = new_element;
	lair_list->size++;
	return (0);
}

void 	ft_fill_end_list(t_lair_list *lair_list, char *content)
{
	t_prompt_list	*new_element;

	if (!(new_element = (t_prompt_list *)malloc(sizeof(t_prompt_list))))
		return (-1);
	new_element->content = content;
	new_element->previous = NULL;
	new_element->next = lair_list->end;
	lair_list->end->next = new_element;
	lair_list->end = new_element;
	lair_list->size++;
	return (0);
}
