/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:42 by loamar            #+#    #+#             */
/*   Updated: 2021/04/16 11:13:13 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

void			status_child(void)
{
	if (WIFEXITED(g_pid))
		g_status = WEXITSTATUS(g_pid);
	if (WIFSIGNALED(g_pid))
	{
		g_status = WTERMSIG(g_pid);
		if (g_status != 131)
			g_status += 128;
	}
}

static	int			check_permission_exec(t_msh *msh, t_list *cmd, char **env)
{
	char	*exec_path;
	int		lock;

	lock = TRUE;
	exec_path = NULL;
	if (cmd == NULL)
		return (ERROR);
	exec_path = get_exec_path(msh, cmd->content);
	if (!exec_path)
		lock = check_permission(cmd->content);
	else
		lock = check_permission(exec_path);
	if (lock == FALSE)
	{
		ft_strdel(&exec_path);
		return (ERROR);
	}
	if (msh->utils->pipe == 0)
		g_pid = fork();
	if (g_pid == 0)
		child_process(msh, cmd, env, exec_path);
	else
		parent_process();
	if (exec_path)
		free(exec_path);
	msh->utils->pipe = 0;
	return (SUCCESS);
}

int					exec_cmd(t_msh *msh, t_list *cmd, char **env, int pipe)
{
	int		status;
	// char	*exec_path;

	// exec_path = NULL;
	g_error = SUCCESS;
	msh->utils->pipe = pipe;
	status = ft_handler_builtins(msh, cmd);
	if (status == SUCCESS)
	{
		g_status = status;
		// exec_path = get_exec_path(msh, cmd->content);
		// if (!exec_path)
		// 	exec_path = ft_strdup(cmd->content);
		// cmd->tab_args[0] = ft_strdup(exec_path);
		// free(exec_path);
		if (msh->utils->pipe == 0)
			free_all(msh, EXIT);
	}
	else if (status == ERROR_BUILTINS)
		if (check_permission_exec(msh, cmd, env) == ERROR)
			return (ERROR);
	if (pipe == 0)
		g_pid = 0;
	if (g_error == ERROR)
		return (ERROR);
	return (SUCCESS);
}
