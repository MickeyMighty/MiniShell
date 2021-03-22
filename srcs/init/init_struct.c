/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 07:27:43 by loamar            #+#    #+#             */
/*   Updated: 2021/03/22 17:43:05 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static t_msh	*init_struct(t_msh *msh)
{
	printf("->1\n");
	if (!(msh = (t_msh*)malloc(sizeof(t_msh))))
		return (NULL);
	printf("->2\n");
	if (!(msh->utils = (t_utils*)malloc(sizeof(t_utils))))
		return (NULL);
	printf("->3\n");
	if (!(msh->data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	printf("->4\n");
	if (fill_separator_tab(msh) == -1)
		return (NULL);
	printf("->5\n");
	return (msh);
}

t_msh 	*init_msh(t_msh *msh)
{
	msh = init_struct(msh);
	if (msh == NULL)
		return (NULL);
	printf("-> ->1\n");
	// msh->lair_list = init_lair_list(msh->lair_list);
	// if (msh->lair_list == NULL)
	// 	return (NULL);
	printf("-> ->2\n");
	// msh->env_lair = init_env_lair(msh->env_lair);
	// printf("-> ->3\n");
	// if (msh->env_lair == NULL)
	// 	return (NULL);
	printf("-> ->4\n");
	msh->data->prompt_data = NULL;
	printf(".\n");
	msh->list = NULL;
	printf("..\n");
	msh->lair_list = NULL;
	printf("...\n");
	// msh->utils = NULL;
	printf("....\n");
	// msh->utils->pid = 0;
	// msh->utils->wpid = 0;
	msh->utils->path = NULL;
	printf(".....\n");
	// msh->utils->status = 0;
	printf("......\n");
	printf("-> ->5\n");
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
