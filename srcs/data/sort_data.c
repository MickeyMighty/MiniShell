/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:48:58 by loamar            #+#    #+#             */
/*   Updated: 2020/12/06 05:35:34 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int 	count_data(t_data *data, char *buf)
{
	int 	test;

	test = 1;
	data->count_data = 0;
	ft_memset(buf, 0, ft_strlen(buf));
	free(buf);
	while (data->prompt_data[data->count_data] != NULL)
	{
		printf("===== %d =======\n", test);
		printf("-> %s\n", data->prompt_data[data->count_data]);
		printf("================\n\n");
		data->count_data++;
		test++;
	}
	return (1);
}

int 	sort_data(t_data *data, char *buf)
{
	t_data		*data;
	int 		size;

	size = 0;
	data = malloc(sizeof(*data));
	if (data == NULL)
		return (0);
	data->prompt_data = ft_split_data(buf, ' ');
	count_data(data, buf);
	return (0);
	//tree_for_data(data);
}
