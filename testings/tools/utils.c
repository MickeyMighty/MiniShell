/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:13:23 by tidminta          #+#    #+#             */
/*   Updated: 2021/03/28 21:13:09 by loamar           ###   ########.fr       */
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

// FONCTIONS POUR CHECK CE QU IL Y A DANS LA LISTE CHAINEE
// static void 	print_list(t_lair_list *lair_list)
// {
// 	int 	test; // pour le printf
//
// 	test = 1; // pour le printf
// 	t_prompt_list *current;
//
// 	current = lair_list->start;
// 	printf("| DEBUT | \n");
// 	while (current != NULL)
// 	{
// 		printf("%d-> %s\n", test, current->content);
// 		current = current->next;
// 		test++; // pour le printf
// 	}
// 	printf("| FIN |\n");
// 	printf("size lair_list -> %d\n", lair_list->size);
// 	printf("first lair_list -> %s\n", lair_list->start->content);
// 	printf("end  lair_list -> %s\n", lair_list->end->content);
// }
//
// // fonction pour print a l enver
// static void 	print_inv_list(t_lair_list *lair_list)
// {
// 	t_prompt_list *current;
//
// 	current = lair_list->end;
// 	printf("[ ");
// 	while(current != NULL)
// 	{
// 		printf("%s : ", current->content);
// 		current = current->previous;
// 	}
// 	printf("]\n");
// }

// ////////////////////////////////////////////////////////////////
// // FONCTIONS POUR CHECK CE QU IL Y A DANS LA LISTE CHAINEE
// static void 	print_list(t_env_lair *env_lair)
// {
// 	int 	test; // pour le printf
//
// 	test = 1; // pour le printf
// 	t_env_list *current;
//
// 	current = env_lair->start;
// 	printf("| DEBUT | \n");
// 	while (current)
// 	{
// 		printf("%d-> %s\n", test, current->first_content);
// 		printf("%d-> %s\n", test, current->second_content);
// 		printf("=========\n");
// 		current = current->next;
// 		test++; // pour le printf
// 	}
// 	printf("| FIN |\n");
// 	printf("size env_lair -> %d\n", env_lair->size);
// 	// printf("first env_lair -> %s\n", env_lair->start->content);
// 	// printf("end  env_lair -> %s\n", env_lair->end->content);
// }
////////////////////////////////////////////////////////////////

static	void		print_list(t_lair_list *lair_list)
{
	int 	test; // pour le printf
	int 	test2; // pour le printf

	test = 1; // pour le printf
	test2 = 0; // pour le printf
	t_list *current;

	current = lair_list->start;
	printf("\n\n| DEBUT | \n");
	while (current != NULL)
	{
		test2 = 1;
		printf("-{%d}[%s]\n", test, current->content);
		if (current->tab_args != NULL)
		{
			while (current->tab_args[test2] != NULL)
			{
				printf("(%d)[%s]\n", test2, current->tab_args[test2]);
				test2++;
			}
		}
		if (current != NULL)
			current = current->next;
		test++; // pour le printf
	}
	printf("size lair_list -> %d\n", lair_list->size);
	printf("first lair_list -> %s\n", lair_list->start->content);
	printf("end  lair_list -> %s\n", lair_list->end->content);
	printf("| FIN |\n\n");
}
