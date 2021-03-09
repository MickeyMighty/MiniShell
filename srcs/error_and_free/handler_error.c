/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 03:33:33 by loamar            #+#    #+#             */
/*   Updated: 2021/03/09 11:31:02 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static void 	msg_error(t_msh *msh, char *msg)
{
	// if (msh->utils->error_multi_line == 1)
	ft_putstr_fd("minishell: ", 2);
	if (msg != NULL)
		ft_putendl_fd(msg, 2);
	else
		ft_putendl_fd(strerror(errno), 2);
}

int 	error_data(t_data *data, int token)
{
	ft_putstr(data->prompt_data[token]);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	return (1);
}

void 	free_all(t_msh *msh)
{
	if (msh)
	{
		if (msh->utils)
			free(msh->utils);
		free_data(msh);
		// free_lair_list(msh);
		free(msh);
	}
}

int 	handler_error(t_msh *msh, char *msg)
{
	msg_error(msh, msg);
	free_all(msh);
	exit(EXIT_FAILURE);
}
