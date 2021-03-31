/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 07:27:43 by loamar            #+#    #+#             */
/*   Updated: 2021/03/31 09:46:09 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static t_msh	*init_struct(t_msh *msh, int key)
{
	if (key == LOOP)
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

t_msh			*init_msh(t_msh *msh, int key)
{
	msh = init_struct(msh, key);
	if (msh == NULL)
		return (NULL);
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
