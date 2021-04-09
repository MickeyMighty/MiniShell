/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 04:42:10 by loamar            #+#    #+#             */
/*   Updated: 2021/04/09 19:09:28 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static	int		check_cmd_list(t_list *element, int size)
{
	if (size > 1)
		if (element->previous->token == SEPARATOR)
			element = element->previous;
	return (error_cmd(element));
}

static	int		check_token_list(t_msh *msh)
{
	t_list		*element;
	int			check_cmd;
	int			size;

	size = 1;
	check_cmd = 0;
	element = msh->lair_list->start;
	if (!element || (element == NULL))
		return (ERROR);
	if (element->token == SEPARATOR)
		return (check_cmd_list(element, size));
	while (element)
	{
		if (element->token == CMD)
			check_cmd = 1;
		else if (element->token == SEPARATOR)
		{
			if (check_cmd == 0)
				return (check_cmd_list(element, size));
			check_cmd = 0;
		}
		size++;
		element = element->next;
	}
	return (SUCCESS);
}

int				handler_list(t_msh *msh)
{
	int		count;

	count = 0;
	msh->lair_list = init_lair_list(msh->lair_list);
	if (msh->lair_list == NULL)
		return (ERROR);
	if (msh->data->prompt_data[count] != NULL)
		ft_fill_empty_list(msh->lair_list, msh->data->prompt_data[count]);
	else
		return (SUCCESS);
	count++;
	while (count < msh->data->size_data)
	{
		ft_fill_end_list(msh->lair_list, msh->data->prompt_data[count]);
		count++;
	}
	free(msh->prompt_data[msh->data->size_data])
	set_token_list(msh);
	msh->utils->pos_list = 1;
	if (create_tab_args(msh) == ERROR)
		return (ERROR);
	if (check_token_list(msh) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
