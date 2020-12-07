/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 07:27:43 by loamar            #+#    #+#             */
/*   Updated: 2020/12/07 16:41:29 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

void 	init_data_lair_list(t_lair_list *lair_list)
{
	// if (!(prompt_list = (t_prompt_list*)malloc(sizeof(t_prompt_list))))
	// 	return (0);
	lair_list->start = NULL;
	lair_list->end = NULL;
	// prompt_list->value = 0;
	lair_list->size = 0;
}
