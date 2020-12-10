/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 05:35:00 by loamar            #+#    #+#             */
/*   Updated: 2020/12/10 15:11:46 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int 	linked_list_data(t_msh *msh)
{
	int 	count;

	count = 0;
	msh->list = NULL;
	// if (!(new_element = (t_prompt_list *)malloc(sizeof(t_prompt_list))))
		// return (-1);
	msh->lair_list = init_data_lair_list(msh->lair_list);
	// printf("msh->data->prompt_data[count] : %s\n", msh->data->prompt_data[0]);
	ft_fill_empty_list(msh->lair_list, msh->data->prompt_data[count]);
	while (count < msh->data->size_data)
	{
		count++;
		ft_fill_end_list(msh->lair_list, msh->data->prompt_data[count]);
	}
	// printf("\nLIST CHAINEE\n");
	// print_list(msh->lair_list);
	return (1);
}

int 	handler_data(t_msh *msh)
{
	// printf("debut de chaine -> %s\n", data->prompt_data[0]);
	linked_list_data(msh);
	return (1);
}
