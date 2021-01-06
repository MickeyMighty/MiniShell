/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:26:48 by loamar            #+#    #+#             */
/*   Updated: 2021/01/06 21:39:20 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	ft_fill_empty_env(t_env_lair *env_lair, char *content)
{
	t_env_list	*new_element;

	if (!(new_element = (t_env_list *)malloc(sizeof(t_env_list))))
		return (-1);
	new_element->content = content;
	new_element->token = 0;
	new_element->previous = env_lair->start;
	new_element->next = env_lair->end;
	env_lair->end = new_element;
	env_lair->start = new_element;
	env_lair->size++;
	return (0);
}

int 	ft_fill_end_env(t_env_lair *env_lair, char *content)
{
	t_env_list	*new_element;

	if (!(new_element = (t_env_list *)malloc(sizeof(t_env_list))))
		return (-1);
	new_element->content = content;
	new_element->token = 0;
	new_element->next = NULL;
	new_element->previous = env_lair->end;
	env_lair->end->next = new_element;
	env_lair->end = new_element;
	env_lair->size++;
	return (0);
}

static	int 	is_empty_env(t_env_lair *env_lair)
{
	if (env_lair == NULL)
		return (1);
	return (-1);
}

t_env_lair		*clear_env(t_env_lair *env_lair)
{
	while (!is_empty_list(env_lair))
		env_lair = pop_back_list(env_lair);
	return (NULL);
}

t_env_lair 		*pop_back_env(t_env_lair *env_lair)
{
	t_env_list 		*temp;

	if (is_empty_env(env_lair))
		return (NULL);
	if (env_lair->start == env_lair->end)
	{
		free (env_lair);
		env_lair = NULL;
		return (NULL);
	}
	temp = env_lair->end;
	env_lair->end->next = NULL;
	temp->next = NULL;
	temp->previous = NULL;
	free(temp);
	temp = NULL;
	env_lair->size--;
	return (env_lair);
}
