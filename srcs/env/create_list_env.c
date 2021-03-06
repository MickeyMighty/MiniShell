/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:26:48 by loamar            #+#    #+#             */
/*   Updated: 2021/04/16 12:48:13 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int				ft_fill_empty_env(t_env_lair *env_lair, char *first_content,
char *second_content)
{
	t_env_list	*new_block;

	if (!(new_block = (t_env_list *)malloc(sizeof(t_env_list))))
		return (-1);
	new_block->first_content = first_content;
	new_block->second_content = second_content;
	new_block->previous = env_lair->start;
	new_block->next = env_lair->end;
	env_lair->end = new_block;
	env_lair->start = new_block;
	env_lair->size++;
	return (0);
}

int				ft_fill_end_env(t_env_lair *env_lair, char *first_content,
char *second_content)
{
	t_env_list	*new_block;

	if (!(new_block = (t_env_list *)malloc(sizeof(t_env_list))))
		return (-1);
	new_block->first_content = first_content;
	new_block->second_content = second_content;
	new_block->next = NULL;
	new_block->previous = env_lair->end;
	env_lair->end->next = new_block;
	env_lair->end = new_block;
	env_lair->size++;
	return (0);
}

static	int		is_empty_env(t_env_lair *env_lair)
{
	if (env_lair->size == 0)
	{
		free(env_lair);
		return (SUCCESS);
	}
	return (ERROR);
}

static	void	free_popback_env(t_env_list *temp)
{
	if (temp->first_content)
		free(temp->first_content);
	if (temp->second_content)
		free(temp->second_content);
	free(temp);
}

int				pop_back_env(t_env_lair *env_lair)
{
	t_env_list	*temp;

	if (is_empty_env(env_lair) == SUCCESS)
		return (ERROR);
	if (env_lair->size == 1)
	{
		temp = env_lair->start;
		env_lair->start = env_lair->start->next;
		if (env_lair->start == NULL)
			env_lair->end = NULL;
		else
			env_lair->start->previous = NULL;
	}
	else
	{
		temp = env_lair->end;
		env_lair->end->previous->next = NULL;
		env_lair->end = env_lair->end->previous;
	}
	free_popback_env(temp);
	env_lair->size--;
	return (SUCCESS);
}
