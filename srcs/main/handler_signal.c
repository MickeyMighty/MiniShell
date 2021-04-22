/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:17:45 by loamar            #+#    #+#             */
/*   Updated: 2021/04/22 22:59:47 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static	void	process(int sign)
{
	if (!kill(g_pid(GET, 0), sign))
	{
		if (sign == SIGQUIT)
		{
			ft_putstr_fd("Quit: 3\n", 1);
			g_status = 131;
			g_error(SET, ERROR);
		}
		else if (sign == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			g_status = 130;
			g_error(SET, ERROR);
		}
	}
	else if (sign == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		g_status = 127;
		g_error(SET, ERROR);
		prompt();
	}
}

void			handler_signal(int sign)
{
	if ((sign == SIGINT || sign == SIGQUIT) && g_pid(GET, 0) != 0)
		process(sign);
	else if (sign == SIGINT || sign == SIGQUIT)
	{
		if (sign == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			g_status = 130;
			g_error(SET, ERROR);
			prompt();
		}
		else if (sign == SIGQUIT)
			ft_putstr_fd("\b\b  \b\b", 1);
	}
	return ;
}
