/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_exec_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzoa <lorenzoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:23:29 by lorenzoa          #+#    #+#             */
/*   Updated: 2021/04/22 23:17:17 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int	is_executable(struct stat	permstat, int flag,
char *cmd)
{
	int		lock;

	lock = TRUE;
	flag = permstat.st_mode & S_IFMT;
	g_status = 126;
	if ((permstat.st_mode & S_IFMT) == S_IFREG)
	{
		if ((permstat.st_mode & S_IXUSR) == 0)
		{
			return_error(ERROR_CMD, cmd, NULL, "Permission denied");
			lock = FALSE;
		}
	}
	if (flag == S_IFDIR)
	{
		return_error(ERROR_CMD, cmd, NULL, "Is a directory");
		lock = FALSE;
	}
	return (lock);
}

int			check_permission(char *cmd)
{
	struct stat		permstat;
	int				lock;
	int				flag;

	ft_bzero(&permstat, sizeof(struct stat));
	flag = stat(cmd, &permstat);
	if (flag == ERROR)
	{
		g_status = 127;
		g_return(SET, ERROR);
		if ((ft_strncmp(cmd, "./", 2) == 0) || cmd[0] == '/')
			return_error(ERROR_CMD, cmd, NULL, ": No such file or directory");
		else
			return_error(ERROR_CMD, cmd, NULL, "command not found");
		return (FALSE);
	}
	lock = is_executable(permstat, flag, cmd);
	return (lock);
}

void		child_process(t_msh *msh, t_list *cmd, char **env, char *exec_path)
{
	int		ret;

	if (!exec_path)
		exec_path = ft_strdup(cmd->content);
	cmd->tab_args[0] = ft_strdup(exec_path);
	ret = execve(exec_path, cmd->tab_args, env);
	free(exec_path);
	if (msh->utils->pipe == 1)
		free_all(msh, EXIT);
	exit(ret);
}

void		parent_process(void)
{
	int		child_status;

	child_status = 0;
	wait(&child_status);
	signal(SIGINT, SIG_IGN);
	if (WIFSIGNALED(child_status) && (g_status != 130
	&& g_status != 131))
	{
		ft_putstr_fd("\n", 2);
		g_status = WTERMSIG(child_status);
	}
	if (WIFEXITED(child_status))
		g_return(SET, child_status);
	if (g_status != 130 && g_status != 131)
		g_status = WEXITSTATUS(child_status);
}
