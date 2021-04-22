/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 07:27:43 by loamar            #+#    #+#             */
/*   Updated: 2021/04/22 22:44:33 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

t_utils			*init_utils(t_utils *utils)
{
	utils->check = 0;
	utils->size_tab = 0;
	utils->pos_args = 1;
	utils->export_check = 0;
	return (utils);
}

static t_msh	*init_struct(t_msh *msh)
{
	if (g_loop(GET, 0) == LOOP)
	{
		if (!(msh = (t_msh*)malloc(sizeof(t_msh))))
			return (NULL);
	}
	if (!(msh->utils = (t_utils*)malloc(sizeof(t_utils))))
		return (NULL);
	if (!(msh->data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	return (msh);
}

t_msh			*init_msh(t_msh *msh)
{
	msh = init_struct(msh);
	if (msh == NULL)
		return (NULL);
	msh->utils->tab_specase = NULL;
	msh->utils->size_tab = 0;
	msh->utils->loop = 0;
	msh->utils->loop2 = 0;
	msh->utils->loop3 = 0;
	msh->list = NULL;
	msh->lair_list = NULL;
	msh->utils->path = NULL;
	return (msh);
}

t_lair_list		*init_lair_list(t_lair_list *lair_list)
{
	if (!(lair_list = (t_lair_list*)malloc(sizeof(t_lair_list))))
		return (NULL);
	lair_list->start = NULL;
	lair_list->end = NULL;
	lair_list->size = 0;
	return (lair_list);
}

t_env_lair		*init_env_lair(t_env_lair *env_lair)
{
	if (!(env_lair = (t_env_lair*)malloc(sizeof(t_env_lair))))
		return (NULL);
	env_lair->start = NULL;
	env_lair->end = NULL;
	env_lair->size = 0;
	return (env_lair);
}
