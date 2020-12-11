/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:56:22 by loamar            #+#    #+#             */
/*   Updated: 2020/12/11 04:06:08 by loamar           ###   ########.fr       */
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
	free(str);
}

static void	free_list(t_msh *msh)
{
	t_list *list;

	while (cub->sprites->next)
	{
		next = cub->sprites->next;
		if (cub->sprites)
			free(cub->sprites);
		cub->sprites = next;
	}
	free(cub->sprites);
}
int 	free_error(t_msh *msh)
{
	if (msh)
	{
		if (msh->utils)
			free(msh->utils)
		if (msh->data)
		{
			if (msh->data->prompt_data)
				free_split(msh->data->prompt_data);
			free(msh->data);
		}
		if (msh->list)
		{

		}
		if (lair_list)
		{

		}
	}
}
