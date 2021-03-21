/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:56:22 by loamar            #+#    #+#             */
/*   Updated: 2021/03/21 15:26:18 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static void		free_split(char **str)
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

void 	free_data(t_msh *msh)
{
	if (msh->data)
	{
		if (msh->data->prompt_data)
			free_split(msh->data->prompt_data);
		free(msh->data);
	}
}

void 	free_list(t_msh *msh)
{
	if (msh->lair_list)
		msh->lair_list = clear_list(msh->lair_list);
	if (msh->env_lair)
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

void 	free_env_lair(t_msh *msh)
{
	if (msh->env_lair)
	{
		msh->env_lair = clear_env(msh->env_lair);
		free(msh->env_lair);
	}
}
