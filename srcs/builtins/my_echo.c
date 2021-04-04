/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 06:06:53 by loamar            #+#    #+#             */
/*   Updated: 2021/04/02 21:54:58 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static	int	check_option(char *str)
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

int			my_echo(t_msh *msh, t_list *element)
{
	int		pos;
	int		option_n;

	option_n = 0;
	pos = 1;
	if (element->tab_args[pos] == NULL)
	{
		ft_putstr_fd("\n", 1);
		return (SUCCESS);
	}
	else
	{
		while (element->tab_args[pos] && check_option(element->tab_args[pos]) == 1)
		{
			option_n = 1;
			pos++;
		}
		while (element->tab_args[pos])
		{
			ft_putstr_fd(element->tab_args[pos], 1);
			if (element->tab_args[pos + 1] != NULL
			&& (check_specase(msh, pos) == 0))
				ft_putstr_fd(" ", 1);
			pos++;
		}
		if (option_n == 0)
			ft_putstr_fd("\n", 1);
	}
	return (SUCCESS);
}
