/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:48:58 by loamar            #+#    #+#             */
/*   Updated: 2020/12/06 09:32:21 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int 	ft_size_data(t_data *data, char *buf)
{
	int 	test;

	test = 1;
	data->size_data = 0;
	ft_memset(buf, 0, ft_strlen(buf));
	free(buf);
	while (data->prompt_data[data->size_data] != NULL)
	{
		printf("===== %d =======\n", test);
		printf("-> %s\n", data->prompt_data[data->size_data]);
		printf("================\n\n");
		data->size_data++;
		test++;
	}
	return (1);
}

int 	sort_data(t_data *data, char *buf)
{
	data = malloc(sizeof(*data));
	if (data == NULL)
		return (0);
	data->prompt_data = ft_split_data(buf, ' ');
	ft_size_data(data, buf);
	return (1);
}
