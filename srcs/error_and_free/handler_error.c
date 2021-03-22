/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 03:33:33 by loamar            #+#    #+#             */
/*   Updated: 2021/03/22 11:35:19 by loamar           ###   ########.fr       */
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

void 	free_all(t_msh *msh, int free_key)
{
	if (msh)
	{
		if (msh->utils)
		{
			if (msh->utils->path)
				free_split(msh->utils->path);
			if (msh->utils->sep_tab)
				free_split(msh->utils->sep_tab);
			// if (msh->utils->tmp_utils)
			// 	free(msh->utils->tmp_utils);
			// if (msh->utils->lair_export)
			// 	free(msh->utils->lair_export);
			free(msh->utils);
		}
		free_data(msh);
		free_list(msh);
		if (free_key == 1)
			free(msh);
	}
}

int 	return_error(t_msh *msh, char *cmd, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	if (cmd != NULL)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
	}
	if (msg != NULL)
		ft_putendl_fd(msg, 2);
	else
		ft_putendl_fd(strerror(errno), 2);
	// free_all(msh);
	// exit(EXIT_FAILURE);
	return (ERROR);
}
