/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 05:35:00 by loamar            #+#    #+#             */
/*   Updated: 2020/12/07 14:22:41 by loamar           ###   ########.fr       */
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


int 	linked_list_data(t_data *data, t_prompt_list *prompt_list, t_lair_list *lair_list)
{
	int 	count;

	count = 0;
	printf("ok 1\n");
	exit(1);
	// prompt_list = ft_fill_empty_list(lair_list, data->prompt_data[count]);
	// printf("ok 2\n");
	// while (count <= data->size_data)
	// {
	// 	count++;
	// 	printf("ok 3\n");
	// 	prompt_list = ft_fill_end_list(lair_list, data->prompt_data[count]);
	// 	printf("ok 4\n");
	// }
	// printf("ok 5\n");
	// print_list(lair_list);
	return (1);
}

int 	handler_data(t_data *data, t_prompt_list *prompt_list, t_lair_list *lair_list)
{
	// if (init_data_lair_list(lair_list) == 0)
	// 	return (0);
	printf("debut de chaine -> %s\n", data->prompt_data[0]);
	linked_list_data(data, prompt_list, lair_list);
	return (1);
}
