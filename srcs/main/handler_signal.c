/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:17:45 by loamar            #+#    #+#             */
/*   Updated: 2021/04/10 11:09:48 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static	void	process(int sign)
{
	if (!kill(g_pid, sign))
	{
		if (sign == SIGQUIT)
		{
			ft_putstr_fd("Quit: 3\n", 1);
			g_status = 131;
			g_error = ERROR;
		}
		else if (sign == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			g_status = 130;
			g_error = ERROR;
		}
	}
	else if (sign == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		g_status = 127;
		g_error = ERROR;
		prompt();
	}
}

void			handler_signal(int sign)
{
	if ((sign == SIGINT || sign == SIGQUIT) && g_pid != 0)
		process(sign);
	else if (sign == SIGINT || sign == SIGQUIT)
	{
		if (sign == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			g_status = 130;
			g_error = ERROR;
			prompt();
		}
		else if (sign == SIGQUIT)
			ft_putstr_fd("\b\b  \b\b", 1);
	}
	return ;
}
