/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:17:45 by loamar            #+#    #+#             */
/*   Updated: 2021/03/21 10:59:15 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

void	handle_signale_ctrl_c(int sig)
{
	g_info.ret = 130;
	ft_lstclear(&g_info.list_input, &clear_token);
	ft_putstr_fd("\n->", 1);
	(void)sig;
}

static void	process(int sign)
{
	if (!kill(global_pid, sign))
	{
		if (sign == SIGQUIT)
		{
			ft_putstr_fd("Quit: 3\n", 1);
			global_status = 131;
		}
		else if (sign == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			global_status = 130;
		}
	}
	else if (sign == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		global_status = 1;
	}
}

void 	handler_signal(int sign)
{
	if ((sign == SIGINT || sign == SIGQUIT) && global_pid != 0)
		process(sign);
	else
	{
		if (sign == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			global_status = 1;
		}
		else if (sign == SIGQUIT)
			ft_putstr_fd("\b\b  \b\b", 1);
	}
}
