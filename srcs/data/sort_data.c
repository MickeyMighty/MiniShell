/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:48:58 by loamar            #+#    #+#             */
/*   Updated: 2020/12/03 17:23:32 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

// int 	check_data(t_data *data)
// {
// 	int 	pos;
// 	int 	check;
// 	int 	error;
//
// 	pos = 0;
// 	check = 0;
// 	error = 0;
// 	while (data->prompt_data[pos] < count_data)
// 	{
//
// 	}
// }

// int make_tree()
// {
// 	t_trees		*bigtree;
//
// 	bigtree = join_tree(join_tree(new_tree(8), new_tree(3), 2), new_tree(4), 6);
// 	print_tree_prefix(bigtree);
// 	printf("Nombre de noeuds : %d\n", count_tree_nodes(bigtree));
// 	clean_tree(bigtree);
// 	return (1);
// }


// int 	tree_for_data(t_data *data)
// {
// 	t_trees 	*tree_data;
// 	int 		count;
//
// 	count = 0;
// 	while (count < data->count_data)
// 		tree_data = join_tree()
//
// }

static int 	split_data(t_data *data, char *buf)
{
	int 	test;

	test = 0;
	data->prompt_data = ft_split_data(buf, ' ');
	data->count_data = 0;
	ft_memset(buf, 0, ft_strlen(buf));
	free(buf);
	// if (!data->prompt_data[data->count_data])
	// 	return (0);
	while (data->prompt_data[data->count_data] != NULL)
	{
		printf("===== %d =======\n", test);
		printf("-> %s\n", data->prompt_data[data->count_data]);
		printf("================\n\n");
		data->count_data++;
		test++;
	}
	//check_block_data(data); recent
	// check_data(data);
	exit(0);
	return (1);
}

int 	sort_data(char *buf)
{
	t_data		*data;
	int 		size;

	size = 0;
	data = malloc(sizeof(*data));
	if (data == NULL)
		return (0);

	split_data(data, buf);
	return (0);
	//tree_for_data(data);
}
