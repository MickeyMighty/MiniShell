/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:56:22 by loamar            #+#    #+#             */
/*   Updated: 2021/04/02 16:17:31 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

void		free_split(char **str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		free(str[index]);
		index++;
	}
	free(str[index]);
	free(str);
}

void		free_list(t_msh *msh, int key)
{
	if (msh->lair_list)
		msh->lair_list = clear_list(msh->lair_list);
	if (msh->env_lair && (key == CTRLD || key == EXIT))
		msh->env_lair = clear_env(msh->env_lair);
}

char		**ft_free_tab(char **tab, int j, t_split_data *split_data)
{
	while (j-- >= 0)
		free(tab[j]);
	free(tab);
	free(split_data);
	return (NULL);
}

void		free_env_lair(t_msh *msh)
{
	if (msh->env_lair)
	{
		msh->env_lair = clear_env(msh->env_lair);
		free(msh->env_lair);
	}
}

void		free_all(t_msh *msh, int free_key)
{
	if (msh)
	{
		if (free_key != CTRLD)
		{
			if (msh->utils)
			{
				if (msh->utils->path)
					free_split(msh->utils->path);
				if (msh->utils->tab_specase)
					free(msh->utils->tab_specase);
				free(msh->utils);
			}
			if (msh->data)
				free(msh->data);
			free_list(msh, free_key);
		}
		if (free_key == EXIT || free_key == CTRLD)
			free(msh);
	}
}
