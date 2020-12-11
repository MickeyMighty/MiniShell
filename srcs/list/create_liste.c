/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_liste.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 04:25:27 by loamar            #+#    #+#             */
/*   Updated: 2020/12/11 01:56:33 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int 	get_token(t_msh *msh, char *content)
{
	if (content[0] == ';');
		return (SEMICOLON);
	if (content[1])
	{
		if (content[0] == '|' && content[1] == '|')
			return (OR);
		if (content[0] == '&' && content[1] == '&')
			return (AND);
		if (content[0] == '>' && content[1] == '>')
			return (CHEVROND);
	}
	if (content[0] == '|')
		return (PIPE);
	if (content[0] == '<')
		return (CHEVRONL);
	if (content[0] == '>')
		return (CHEVRONR);
	return (0);
}

int 	ft_fill_empty_list(t_lair_list *lair_list, char *content)
{
	t_prompt_list	*new_element;

	if (!(new_element = (t_prompt_list *)malloc(sizeof(t_prompt_list))))
		return (-1);
	new_element->content = content;
	new_element->token = 0;
	new_element->previous = lair_list->start;
	new_element->next = lair_list->end;
	lair_list->end = new_element;
	lair_list->start = new_element;
	lair_list->size++;
	return (0);
}

int 	ft_fill_end_list(t_lair_list *lair_list, char *content)
{
	t_prompt_list	*new_element;

	if (!(new_element = (t_prompt_list *)malloc(sizeof(t_prompt_list))))
		return (-1);
	new_element->content = content;
	new_element->token = get_token(msh, content);
	new_element->next = NULL;
	new_element->previous = lair_list->end;
	lair_list->end->next = new_element;
	lair_list->end = new_element;
	lair_list->size++;
	return (0);
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
