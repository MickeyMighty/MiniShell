/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:56:22 by loamar            #+#    #+#             */
/*   Updated: 2021/04/09 10:14:53 by loamar           ###   ########.fr       */
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
	if (key == ENDLOOP && msh->lair_list && msh->lair_list->size > 0)
		clear_list(msh->lair_list);
	if (msh->env_lair && msh->env_lair->size > 0
	&& (key == CTRLD || key == EXIT))
		clear_env(msh->env_lair);
}

char		**ft_free_tab(char **tab, int j, t_split_data *split_data)
{
	while (j-- >= 0)
		free(tab[j]);
	free(tab);
	free(split_data);
	return (NULL);
}
