/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 06:06:53 by loamar            #+#    #+#             */
/*   Updated: 2021/04/06 17:21:35 by lorenzoamar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static	int		check_option(char *str)
{
	int		pos;

	pos = 0;
	if (ft_strncmp("-n", str, 2) == 0)
	{
		pos = 2;
		if (str[pos])
		{
			while (str[pos] == 'n')
				pos++;
			if (str[pos] == '\0')
				return (1);
			else if (str[pos] != 'n')
				return (0);
		}
		return (1);
	}
	return (0);
}

static	void	print_echo(t_msh *msh, t_list *element)
{
	ft_putstr_fd(element->tab_args[msh->utils->pos_echo], 1);
	if (element->tab_args[msh->utils->pos_echo + 1] != NULL
	&& (check_specase(msh, msh->utils->pos_echo) == 0))
		ft_putstr_fd(" ", 1);
}

int				my_echo(t_msh *msh, t_list *element)
{
	msh->utils->option_n = 0;
	msh->utils->pos_echo = 1;
	if (element->tab_args[msh->utils->pos_echo] == NULL)
	{
		ft_putstr_fd("\n", 1);
		return (SUCCESS);
	}
	else
	{
		while (element->tab_args[msh->utils->pos_echo] &&
		check_option(element->tab_args[msh->utils->pos_echo]) == 1)
		{
			msh->utils->option_n = 1;
			msh->utils->pos_echo++;
		}
		while (element->tab_args[msh->utils->pos_echo])
		{
			print_echo(msh, element);
			msh->utils->pos_echo++;
		}
		if (msh->utils->option_n == 0)
			ft_putstr_fd("\n", 1);
	}
	return (SUCCESS);
}
