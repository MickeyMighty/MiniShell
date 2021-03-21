/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 07:27:43 by loamar            #+#    #+#             */
/*   Updated: 2021/03/21 16:15:35 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static t_msh	*init_struct(t_msh *msh)
{
	if (!(msh = (t_msh*)malloc(sizeof(t_msh))))
		return (NULL);
	if (!(msh->utils = (t_utils*)malloc(sizeof(t_utils))))
		return (NULL);
	if (!(msh->data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	if (fill_separator_tab(msh) == -1)
		return (NULL);
}

t_msh 	*init_msh(t_msh *msh)
{
	msh = init_struct(msh);
	msh->lair_list = init_lair_list(msh->lair_list);
	if (msh->lair_list == NULL)
		return (ERROR);
	msh->env_lair = init_env_lair(msh->env_lair);
	if (msh->env_lair == NULL)
		return (ERROR);
	if (msh == NULL)
		return (NULL);
	msh->data = NULL;
	msh->list = NULL;
	msh->lair_list = NULL;
	msh->utils = NULL;
	msh->utils->pid = 0;
	msh->utils->wpid = 0;
	msh->utils->path = NULL;
	msh->utils->status = 0;
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

t_env_lair	*init_env_lair(t_env_lair *env_lair)
{
	if (!(env_lair = (t_env_lair*)malloc(sizeof(t_env_lair))))
	return (NULL);
	env_lair->start = NULL;
	env_lair->end = NULL;
	env_lair->size = 0;
	return (env_lair);
}
