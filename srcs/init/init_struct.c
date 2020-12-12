/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 07:27:43 by loamar            #+#    #+#             */
/*   Updated: 2020/12/12 06:03:49 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

t_msh 	*init_msh(t_msh *msh)
{
	if (!(msh = (t_msh*)malloc(sizeof(t_msh))))
		return (NULL);
	msh->data = NULL;
	msh->list = NULL;
	msh->lair_list = NULL;
	msh->utils = NULL;
	if (!(msh->utils = (t_utils*)malloc(sizeof(t_utils))))
		return (NULL);
	msh->utils->check_opt = 0;
	msh->utils->check_arg = 0;
	msh->utils->pid = 0;
	msh->utils->wpid = 0;
	msh->utils->status = 0;
	msh->utils->error_multi_line = 0;
	if (fill_separator_tab(msh) == -1)
		return (NULL);
	return (msh);
}

t_lair_list 	*init_lair_list(t_lair_list *lair_list)
{
	if (!(lair_list = (t_lair_list*)malloc(sizeof(t_lair_list))))
		return (NULL);
	lair_list->start = NULL;
	lair_list->end = NULL;
	lair_list->size = 0;
	return (lair_list);
}
