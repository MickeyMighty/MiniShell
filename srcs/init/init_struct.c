/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 07:27:43 by loamar            #+#    #+#             */
/*   Updated: 2021/04/29 15:10:21 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static t_msh	*init_struct(t_msh *msh)
{
	if (g_loop(GET, 0) == LOOP)
	{
		if (!(msh = (t_msh*)malloc(sizeof(t_msh))))
			return (NULL);
		if (!(msh->termcap = (t_termcap*)malloc(sizeof(t_termcap))))
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
	msh->termcap->start_col = 0;
	msh->termcap->start_row = 0;
	msh->termcap->end_col = 0;
	msh->termcap->end_row = 0;
	msh->termcap->col = 0;
	msh->termcap->row = 0;
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

t_history_lair		*init_history_lair(t_history_lair *history_lair)
{
	if (!(history_lair = (t_history_lair*)malloc(sizeof(t_history_lair))))
		return (NULL);
	history_lair->start = NULL;
	history_lair->end = NULL;
	history_lair->size = 0;
	return (history_lair);
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
