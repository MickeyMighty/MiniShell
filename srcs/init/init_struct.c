/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 07:27:43 by loamar            #+#    #+#             */
/*   Updated: 2021/04/27 11:19:29 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

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

t_term_lair		*init_term_lair(t_term_lair *term_lair)
{
	if (!(term_lair = (t_term_lair*)malloc(sizeof(t_term_lair))))
		return (NULL);
	term_lair->start = NULL;
	term_lair->end = NULL;
	term_lair->size = 0;
	return (term_lair);
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
