/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_termcap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 02:33:35 by loamar            #+#    #+#             */
/*   Updated: 2021/04/27 11:22:02 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int				ft_fill_empty_term(t_term_lair *term_lair, char *content)
{
	t_term_list	*new_element;

	if (!(new_element = (t_term_list *)malloc(sizeof(t_list))))
		return (-1);
	new_element->content = content;
	new_element->previous = term_lair->start;
	new_element->next = term_lair->end;
	term_lair->end = new_element;
	term_lair->start = new_element;
	term_lair->size++;
	return (0);
}

int				ft_fill_start_term(t_term_lair *term_lair, char *content)
{
	t_term_list	*new_element;

	if (!(new_element = (t_term_list *)malloc(sizeof(t_term_list))))
		return (-1);
	new_element->content = content;
	new_element->previous = NULL;
	new_element->next = term_lair->start;
	term_lair->start->previous = new_element;
	term_lair->start = new_element;
	term_lair->size++;
	return (0);
}

int				clear_term(t_term_lair *term_lair)
{
	int		loop;

	loop = 0;
	while (loop == 0)
	{
		if (pop_back_term(term_lair) == ERROR)
			loop = 1;
	}
	return (SUCCESS);
}
