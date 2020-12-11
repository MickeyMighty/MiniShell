/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:13:10 by loamar            #+#    #+#             */
/*   Updated: 2020/12/11 02:21:52 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

int 	data_check(t_msh *msh)
{
	int 	count;
	int 	pos;

	count = 0;
	while (count <= msh->data->count_data)
	{
		pos = 0;
		if (msh->data->prompt_data[count][pos] == '\'')
		{
			pos++;
			while (msh->data->prompt_data[count][pos] != '\'')
			{
				if (msh->data->prompt_data[count][pos] == '\0')
					return (-1);
				pos++;
			}
		}
		else if (msh->data->prompt_data[count][pos] == '\")
		{
			pos++;
			while (msh->data->prompt_data[count][pos] != '\")
			{
				if (msh->data->prompt_data[count][pos] == '\0')
					return (-1);
				pos++;
			}
		}
		count++;
	}
	return (1);
}
