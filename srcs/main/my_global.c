/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 22:24:44 by loamar            #+#    #+#             */
/*   Updated: 2021/04/22 23:15:19 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int		g_pid(int mode, int value)
{
    static pid_t	pid;

    if (mode == 1)
       pid = value;
    return (pid);
}

int		g_loop(int mode, int value)
{
    static int	loop;

    if (mode == 1)
       loop = value;
    return (loop);
}

int		g_error(int mode, int value)
{
    static int	error;

    if (mode == 1)
       error = value;
    return (error);
}

int		g_error_msg(int mode, int value)
{
    static int	error_msg;

    if (mode == 1)
       error_msg = value;
    return (error_msg);
}

int		g_return(int mode, int value)
{
	static int	return_value;

	if (mode == 1)
		return_value = value;
	return (return_value);
}
