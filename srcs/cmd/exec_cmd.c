/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:42 by loamar            #+#    #+#             */
/*   Updated: 2021/04/04 10:21:40 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"
//de la liste
static t_list 		*check_exec(t_msh *msh, t_list *cmd, char **env)
{
	if (cmd->token != CMD)
	{
		return_error(ERROR_CMD, cmd->content, NULL, "syntax error near unexpected token");
		return (NULL);
	}
	return (cmd);
}

static int	is_executable(t_msh *msh, struct stat	permstat, int flag, char *cmd)
{
	int		lock;

	lock = TRUE;
	flag = permstat.st_mode & S_IFMT;
	global_status = 126;
	if ((permstat.st_mode & S_IFMT) == S_IFREG)
	{
		if ((permstat.st_mode & S_IXUSR) == 0)
		{
			return_error(ERROR_CMD, cmd, NULL, "Permission denied");
			lock = false;
		}
	}
	if (flag == S_IFDIR)
	{
		return_error(ERROR_CMD, cmd, NULL, "Is a directory");
		lock = FALSE;
	}
	return (lock);
}

static int		check_permission(t_msh *msh, char *cmd)
{
	struct	stat	permstat;
	int				lock;
	int				flag;

	ft_bzero(&permstat, sizeof(struct stat));
	flag = stat(cmd, &permstat);
	if (flag == ERROR)
	{
		global_status = 127;
		global_return = ERROR;
		if ((ft_strncmp(cmd, "./", 2) == 0) || cmd[0] == '/')
			return_error(ERROR_CMD, cmd, NULL,": No such file or directory");
		else
			return_error(ERROR_CMD, cmd, NULL, "command not found");
		return (FALSE);
	}
	lock = is_executable(msh, permstat, flag, cmd);
	return (lock);
}

static	void 	child_process(t_msh *msh, t_list *cmd, char **env, char *exec_path)
{
	int 	count;
	int 	ret;

	count = 0;
	if (!exec_path)
		exec_path = ft_strdup(cmd->content);
	cmd->tab_args[0] = ft_strdup(exec_path);
	ret = execve(exec_path, cmd->tab_args, env);
	free(exec_path);
	exit(ret);
}

static	void 	parent_process(t_msh *msh, t_list *cmd)
{
	int 	child_status;

	child_status = 0;
	signal(SIGINT, SIG_IGN);
	wait(&child_status);
	if (WIFSIGNALED(child_status))
	{
		ft_putstr_fd("\n", 2);
		global_status = WTERMSIG(child_status);
	}
	if (WIFEXITED(child_status))
		global_return = child_status;
	global_status = WEXITSTATUS(child_status);
}

int 	exec_cmd(t_msh *msh, t_list *cmd, char **env)
{
	char 	*exec_path;
	int 	count;
	int 	lock;
	int		status;

	lock = true;
	global_error = SUCCESS;
	exec_path = NULL;
	status = ft_handler_builtins(msh, cmd, env);
	if (status == SUCCESS)
		global_status = status;
	else if (status == ERROR_BUILTINS)
	{
		if (cmd == NULL)
			return (ERROR);
		exec_path = get_exec_path(msh, cmd->content);
		count = -1;
		if (!exec_path)
			lock = check_permission(msh, cmd->content);
		else
			lock = check_permission(msh, exec_path);
		if (lock == FALSE)
		{
			ft_strdel(&exec_path);
			return (ERROR);
		}
		if (msh->utils->pipe == 0)
			global_pid = fork();
		if (global_pid == 0)
			child_process(msh, cmd, env, exec_path);
		else
			parent_process(msh, cmd);
	}
	global_pid = 0;
	if (exec_path)
		free(exec_path);
	if (global_error == ERROR)
		return (ERROR);
	return (SUCCESS);
}
