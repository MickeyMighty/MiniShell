/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 04:42:10 by loamar            #+#    #+#             */
/*   Updated: 2020/12/12 06:05:22 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int 	linked_list_data(t_msh *msh)
{
	int 	count;

	count = 0;
	msh->list = NULL;
	msh->lair_list = init_lair_list(msh->lair_list);
	if (msh->lair_list == NULL)
		return (ERROR);
	ft_fill_empty_list(msh->lair_list, msh->data->prompt_data[count]);
	while (count < msh->data->size_data)
	{
		count++;
		ft_fill_end_list(msh->lair_list, msh->data->prompt_data[count]);
	}
	// print_list(msh->lair_list);
	return (SUCCESS);
}

int 	handler_list(t_msh *msh)
{
	int 	ret;

	ret = 0;
	ret = linked_list_data(msh);
	if (ret == ERROR)
		return (ERROR);
	set_token_list(msh);
	free_data(msh);
	return (SUCCESS);
}
