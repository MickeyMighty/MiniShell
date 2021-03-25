/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 03:33:33 by loamar            #+#    #+#             */
/*   Updated: 2021/03/24 13:08:48 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	error_data(t_data *data, int token)
{
	ft_putstr(data->prompt_data[token]);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	return (1);
}

void		free_tab_args(t_msh *msh, char **str)
{
	int		index;
	int 	limite;

	limite = msh->utils->size_opt_arg + 1;
	index = 0;
	while (index <= limite)
	{
		free(str[index]);
		index++;
	}
	free(str[index]);
	free(str);
}

int 	return_error(t_msh *msh, char *cmd, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	if (global_error == ERROR_CMD)
	{
		if (msg)
		{
			ft_putstr_fd(msg, 2);
			ft_putstr_fd(" ", 2);
		}
		if (cmd)
		{
			ft_putstr_fd("\'", 2);
			ft_putstr_fd(cmd, 2);
			ft_putendl_fd("\'", 2);
		}
	}
	else if (global_error != ERROR_CMD)
	{
		if (cmd != NULL)
		{
			ft_putstr_fd(cmd, 2);
			ft_putstr_fd(": ", 2);
		}
		if (msg != NULL)
			ft_putendl_fd(msg, 2);
	}
	else
		ft_putendl_fd(strerror(errno), 2);
	return (ERROR);
}
