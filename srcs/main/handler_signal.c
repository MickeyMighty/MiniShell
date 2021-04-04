/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:17:45 by loamar            #+#    #+#             */
/*   Updated: 2021/03/31 10:22:08 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static void	process(int sign)
{
	if (!kill(global_pid, sign))
	{
		if (sign == SIGQUIT)
		{
			ft_putstr_fd("Quit: 3\n", 1);
			global_status = 131;
			global_error = ERROR;
		}
		else if (sign == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			global_status = 130;
			global_error = ERROR;
		}
	}
	else if (sign == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		global_status = 130;
		global_error = ERROR;
		prompt();
	}
}

void 	handler_signal(int sign)
{
	if ((sign == SIGINT || sign == SIGQUIT) && global_pid != 0)
		process(sign);
	else if (sign == SIGINT || sign == SIGQUIT)
	{
		if (sign == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			global_status = 130;
			global_error = ERROR;
			prompt();
		}
		else if (sign == SIGQUIT)
			ft_putstr_fd("\b\b  \b\b", 1);
	}
	return ;
}
