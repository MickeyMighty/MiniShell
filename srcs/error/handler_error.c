/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 03:33:33 by loamar            #+#    #+#             */
/*   Updated: 2020/12/11 04:03:31 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static void 	msg_error(t_msh *msh)
{
	if (msh->utils->error_multi_line == 1)
		ft_putstr_fd("missing quote\n", 2);
	else
		ft_putstr_fd(strerror(errno), 2);
}

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

int 	error_data(t_data *data, int token)
{
	ft_putstr(data->prompt_data[token]);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	return (1);
}

int 	free_msh(t_msh *msh)
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

int 	handler_error(t_msh *msh)
{
	;
}
