/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 00:50:24 by loamar            #+#    #+#             */
/*   Updated: 2021/04/22 22:45:51 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static	void	return_error_cmd(char *cmd, char *msg)
{
	if (cmd != NULL)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
	}
	if (msg != NULL)
		ft_putstr_fd(msg, 2);
}

static	void	return_error_token(char *cmd, char *msg)
{
	if (msg)
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd(" ", 2);
	}
	if (cmd)
	{
		ft_putstr_fd("`", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd("\'", 2);
	}
}

static	void	return_error_args(char *cmd, char *arg, char *msg, int type)
{
	if (cmd != NULL)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
	}
	if (arg != NULL)
	{
		if (type == ERROR_QTE)
			ft_putstr_fd("`", 2);
		ft_putstr_fd(arg, 2);
		if (type == ERROR_QTE)
			ft_putstr_fd("\'", 2);
	}
	if (msg != NULL)
		ft_putstr_fd(msg, 2);
}

int				return_error(int type, char *cmd, char *arg, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	if (type == ERROR_ARGS || type == ERROR_QTE)
		return_error_args(cmd, arg, msg, type);
	else if (type == ERROR_MULTI)
		ft_putstr_fd(msg, 2);
	else if (type == ERROR_TOKEN)
		return_error_token(cmd, msg);
	else if (type == ERROR_CMD)
		return_error_cmd(cmd, msg);
	else if (type == ERROR_MSG)
		ft_putstr_fd(msg, 2);
	else
		ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	g_error(SET, ERROR);
	return (ERROR);
}
