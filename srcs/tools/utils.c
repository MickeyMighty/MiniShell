/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:13:23 by tidminta          #+#    #+#             */
/*   Updated: 2020/12/10 15:38:28 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static void 	print_list(t_lair_list *lair_list)
{
	int 	test; // pour le printf

	test = 1; // pour le printf
	t_prompt_list *current;

	current = lair_list->start;
	printf("| DEBUT | \n");
	while (current != NULL)
	{
		printf("content -> %s\n", current->content);
		printf("token -> %d\n", current->token);
		current = current->next;
		test++; // pour le printf
	}
	printf("| FIN |\n");
	printf("size lair_list -> %d\n", lair_list->size);
	printf("first lair_list -> %s\n", lair_list->start->content);
	printf("end  lair_list -> %s\n", lair_list->end->content);
}

// fonction pour print a l enver
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