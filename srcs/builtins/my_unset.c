/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:56:45 by loamar            #+#    #+#             */
/*   Updated: 2021/04/16 11:12:27 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static	int		pop_env(t_msh *msh, int pos)
{
	t_env_list	*delete_element;
	t_env_list	*now_element;

	msh->utils->pos = 1;
	if (msh->env_lair->size == 0)
		return (-1);
	if (msh->env_lair->size == 1)
		return (clear_env(msh->env_lair));
	now_element = msh->env_lair->start;
	while (msh->utils->pos++ < pos)
		now_element = now_element->next;
	delete_element = now_element;
	if (now_element->next != NULL)
		now_element->next->previous = now_element->previous;
	else
		msh->env_lair->end = now_element->previous;
	if (now_element->previous != NULL)
		now_element->previous->next = now_element->next;
	if (delete_element->first_content)
		free(delete_element->first_content);
	if (delete_element->second_content)
		free(delete_element->second_content);
	free(delete_element);
	msh->env_lair->size--;
	return (0);
}

static int		find_env(t_msh *msh, char *content, int index)
{
	t_env_list	*element;

	if (!content)
		return (-1);
	element = msh->env_lair->start;
	if (!element || element == NULL)
		return (-1);
	index = 1;
	while (element)
	{
		if (element && element->first_content)
		{
			if (ft_strcmp(content, element->first_content) == 0)
				return (index);
		}
		if (element)
			element = element->next;
		index++;
	}
	return (-1);
}

int				my_unset(t_msh *msh, t_list *element)
{
	size_t	pos;
	ssize_t	index;

	g_status = 0;
	if (!element->tab_args[1])
		return (SUCCESS);
	pos = 1;
	while (element->tab_args[pos])
	{
		index = find_env(msh, element->tab_args[pos], pos);
		if (index != -1)
		{
			if (element->tab_args[pos])
				pop_env(msh, index);
		}
		else
		{
			return_error(ERROR_QTE, "unset", element->tab_args[pos],
			": not a valid identifier");
			g_status = 1;
		}
		pos++;
	}
	return (SUCCESS);
}
