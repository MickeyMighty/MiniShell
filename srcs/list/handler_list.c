/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 05:35:00 by loamar            #+#    #+#             */
/*   Updated: 2020/12/11 02:40:40 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int 	check_if_option(t_msh *msh, int count)
{
	// probleme pour echo
	if (msh->data->prompt_data[count][0] == '-'
	|| (((msh->data->prompt_data[count][0] == '\'')
	|| (msh->data->prompt_data[count][0] == '\"'))
	&& msh->data->prompt_data[count][1] == '-'))
		return (1);
	else
		return (0);
}

// static int 	check_if_argument(t_msh *msh, int count)
// {
// 	if (msh->data->prompt_data[count] ==)
// 	return (1);
// }

static int 	linked_list_data(t_msh *msh)
{
	int 	count;

	count = 0;
	msh->list = NULL;
	msh->lair_list = init_data_lair_list(msh->lair_list);
	ft_fill_empty_list(msh->lair_list, msh->data->prompt_data[count]);
	while (count < msh->data->size_data)
	{
		count++;
		msh->utils->check_opt = 0;
		msh->utils->check_arg = 0;
		while (check_if_option(msh, count) == 1)
		{
			count++;
			msh->utils->check_opt = 1;
		}
		ft_fill_end_list(msh->lair_list, msh->data->prompt_data[count]);
	}
	// printf("\nLIST CHAINEE\n");
	// print_list(msh->lair_list);
	return (1);
}

int 	handler_list(t_msh *msh)
{
	// printf("debut de chaine -> %s\n", data->prompt_data[0]);
	linked_list_data(msh);

	return (1);
}
