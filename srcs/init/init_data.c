/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 07:27:43 by loamar            #+#    #+#             */
/*   Updated: 2020/12/08 03:25:42 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

t_lair_list 	*init_data_lair_list(t_lair_list *lair_list)
{
	if (!(lair_list = (t_lair_list*)malloc(sizeof(t_lair_list))))
		return (0);
	lair_list->start = NULL;
	lair_list->end = NULL;
	// prompt_list->value = 0;
	lair_list->size = 0;
	return (lair_list);
}
