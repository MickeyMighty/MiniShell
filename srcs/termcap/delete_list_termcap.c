/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_list_termcap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 02:34:50 by loamar            #+#    #+#             */
/*   Updated: 2021/04/27 11:22:49 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static	int		is_empty_term(t_term_lair *term_lair)
{
	if (term_lair->size == 0)
	{
		free(term_lair);
		return (SUCCESS);
	}
	return (ERROR);
}

static	void	free_popback_term(t_term_list *temp)
{
	if (temp->content)
		free(temp->content);
	free(temp);
}

int				pop_back_term(t_term_lair *term_lair)
{
	t_term_list		*temp;

	if (is_empty_term(term_lair) == SUCCESS)
		return (ERROR);
	if (term_lair->size == 1)
	{
		temp = term_lair->start;
		term_lair->start = term_lair->start->next;
		if (term_lair->start == NULL)
			term_lair->end = NULL;
		else
			term_lair->start->previous = NULL;
	}
	else
	{
		temp = term_lair->end;
		term_lair->end->previous->next = NULL;
		term_lair->end = term_lair->end->previous;
	}
	free_popback_term(temp);
	term_lair->size--;
	return (SUCCESS);
}
