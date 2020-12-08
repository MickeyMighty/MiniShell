/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 05:35:00 by loamar            #+#    #+#             */
/*   Updated: 2020/12/08 18:37:29 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static void 	print_list(t_lair_list *lair_list)
{
	t_prompt_list *current;

	current = lair_list->start;
	printf("[ ");
	while (current != NULL)
	{
		printf("%s ", current->content);
		current = current->next;
	}
	printf("]\n");
}

static void 	print_inv_list(t_lair_list *lair_list)
{
	t_prompt_list *current;

	current = lair_list->end;
	printf("[ ");
	while(current != NULL)
	{
		printf("%s : ", current->content);
		current = current->previous;
	}
	printf("]\n");
}


static int 	linked_list_data(t_msh *msh)
{
	int 	count;

	count = 0;
	msh->list = NULL;
	// printf("ok 1\n");
	// if (!(new_element = (t_prompt_list *)malloc(sizeof(t_prompt_list))))
		// return (-1);
	msh->lair_list = init_data_lair_list(msh->lair_list);
	// printf("msh->data->prompt_data[count] : %s\n", msh->data->prompt_data[0]);
	// ft_fill_empty_list(lair_list, data->prompt_data[count]);
	// printf("ok 2\n");
	// while (count <= data->size_data)
	// {
	// 	count++;
	// 	// printf("ok 3\n");
	// 	ft_fill_end_list(lair_list, data->prompt_data[count]);
	// 	// printf("ok 4\n");
	// }
	// printf("ok 5\n");
	// print_list(lair_list);
	exit(1);
	return (1);
}

int 	handler_data(t_msh *msh)
{
	// printf("debut de chaine -> %s\n", data->prompt_data[0]);
	linked_list_data(msh);
	return (1);
}
