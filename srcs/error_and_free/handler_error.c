/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 03:33:33 by loamar            #+#    #+#             */
/*   Updated: 2021/05/05 17:56:54 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

void			free_all(t_msh *msh, int free_key)
{
	if (msh && (g_loop(GET, 0) != LOOP))
	{
		// if (msh->termcap)
		// {
			// if (msh->termcap->line)
			// 	free(msh->termcap->line);
		// }
		if (msh->utils && (free_key == ENDLOOP || free_key == EXIT))
		{
			if (msh->utils->path)
			{
				free_split(msh->utils->path);
				msh->utils->path = NULL;
			}
			if (msh->utils->tab_specase)
				free(msh->utils->tab_specase);
			free(msh->utils);
		}
		if (msh->data && (free_key == ENDLOOP || free_key == EXIT))
			free(msh->data);
		free_list(msh, free_key);
		if (free_key == EXIT || free_key == CTRLD)
			free(msh);
	}
}

int				error_data(t_data *data, int token)
{
	ft_putstr(data->prompt_data[token]);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	return (1);
}
