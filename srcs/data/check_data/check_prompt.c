/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 08:55:06 by loamar            #+#    #+#             */
/*   Updated: 2020/12/06 09:42:41 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

static int	ft_create_lair_tab(t_data *data)
{
	int 	test;

	test = 0;
	printf("\npoet\n");
	if (!(data->lair_tab = (char**)malloc(sizeof(char*) * 10)))
		return (0);
	data->lair_tab[PIPE] = "|";
	data->lair_tab[SEMICOLON] = ";";
	data->lair_tab[CHEVRONL] = "<";
	data->lair_tab[CHEVRONR] = ">";
	data->lair_tab[CHEVROND] = ">>";
	data->lair_tab[AND] = "&&";
	data->lair_tab[OR] = "||";
	data->lair_tab[VARIABLE] = "$";
	data->lair_tab[SQ] = "\"";
	data->lair_tab[DQ] = "\'";
	data->lair_tab[10] = 0;
	while (test <= 10)
	{
		printf("===== %d =======\n", test);
		printf("-> %s\n", data->lair_tab[test]);
		printf("================\n\n");
		test++;
	}
	exit(0);
}

// static int 	ft_check_string(char *content)
// {
// 	int 	pos;
//
// 	pos = 0;
// 	if (data->check == 1)
// 		return (0);
// 	while (content[pos] != '\0')
// 	{
// 		if ()
// 		pos++
// 	}
// }

int 	check_prompt(t_data *data)
{
	int 	count;

	count = 0;
	data->check = 0;
	ft_create_lair_tab(data);
	// while (count < data->size_data)
	// {
	// 	if (ft_check(data->prompt_data[count]) == 0)
	// 		return (0);
	// 	count++;
	// }
	return (1);
}
