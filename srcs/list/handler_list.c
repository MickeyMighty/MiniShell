/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 04:42:10 by loamar            #+#    #+#             */
/*   Updated: 2021/03/31 10:04:04 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"
//
// static	void		print_list(t_lair_list *lair_list)
// {
// 	int 	test; // pour le printf
// 	int 	test2; // pour le printf
//
// 	test = 1; // pour le printf
// 	test2 = 0; // pour le printf
// 	t_list *current;
//
// 	current = lair_list->start;
// 	printf("\n\n| DEBUT | \n");
// 	while (current != NULL)
// 	{
// 		test2 = 1;
// 		printf("-{%d}[%s]\n", test, current->content);
// 		if (current->tab_args != NULL)
// 		{
// 			while (current->tab_args[test2] != NULL)
// 			{
// 				printf("(%d)[%s]\n", test2, current->tab_args[test2]);
// 				test2++;
// 			}
// 		}
// 		if (current != NULL)
// 			current = current->next;
// 		test++; // pour le printf
// 	}
// 	printf("size lair_list -> %d\n", lair_list->size);
// 	printf("first lair_list -> %s\n", lair_list->start->content);
// 	printf("end  lair_list -> %s\n", lair_list->end->content);
// 	printf("| FIN |\n\n");
// }

static	int		check_cmd_list(t_msh *msh, t_list *element, int size)
{
	if (size > 1)
		if (element->previous->token == SEPARATOR)
			element = element->previous;
	return (error_cmd(msh, element));
}

static	int		check_token_list(t_msh *msh)
{
	t_list		*element;
	int			check_cmd;
	int			size;

	size = 1;
	check_cmd = 0;
	element = msh->lair_list->start;
	if (!element || (element == NULL))
		return (ERROR);
	if (element->token == SEPARATOR)
		return (check_cmd_list(msh, element, size));
	while (element)
	{
		if (element->token == CMD)
			check_cmd = 1;
		else if (element->token == SEPARATOR)
		{
			if (check_cmd == 0)
				return (check_cmd_list(msh, element, size));
			check_cmd = 0;
		}
		size++;
		element = element->next;
	}
	return (SUCCESS);
}

int				handler_list(t_msh *msh)
{
	int		count;
	int		pos;
	int		qte;
	char	*tmp;

	count = 0;
	msh->lair_list = init_lair_list(msh->lair_list);
	if (msh->lair_list == NULL)
		return (ERROR);
	if (msh->data->prompt_data[count] != NULL)
		ft_fill_empty_list(msh->lair_list, msh->data->prompt_data[count]);
	else
		return (SUCCESS);
	while (++count < msh->data->size_data)
		ft_fill_end_list(msh->lair_list, msh->data->prompt_data[count]);
	set_token_list(msh);
	msh->utils->pos_list = 1;
	if (create_tab_args(msh) == ERROR)
		return (ERROR);
	if (check_token_list(msh) == ERROR)
		return (ERROR);
	// print_list(msh->lair_list);
	return (SUCCESS);
}
