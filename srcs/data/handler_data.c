/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:48:58 by loamar            #+#    #+#             */
/*   Updated: 2020/12/11 02:48:49 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int 	ft_size_data(t_msh *msh, char *buf)
{
	// int 	test; // pour le test ( a ne pas supp)
	//
	// test = 1; // pour le test ( a ne pas supp)
	msh->data->size_data = 0;
	ft_memset(buf, 0, ft_strlen(buf));
	free(buf);
	while (msh->data->prompt_data[msh->data->size_data] != NULL)
	{
		// printf("===== %d =======\n", test);
		// printf("-> %s\n", msh->data->prompt_data[msh->data->size_data]);
		// printf("================\n\n");
		msh->data->size_data++;
		// test++;
	}
	return (1);
}

int 	handler_data(t_msh *msh, char *buf)
{
	msh->data = (t_data *)malloc(sizeof(t_data));
	if (msh->data == NULL)
		return (0);
	msh->data->prompt_data = ft_split_data(buf, ' ');
	ft_size_data(msh, buf);
	if (data_check(msh) == -1)
		return (-1);
	return (1);
}
