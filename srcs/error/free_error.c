/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:56:22 by loamar            #+#    #+#             */
/*   Updated: 2020/12/11 17:04:08 by loamar           ###   ########.fr       */
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

void 	free_lair_list(t_msh *msh)
{
	if (msh->lair_list)
	{
		msh->lair_list = clear_list(msh->lair_list);
	}
}
