/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:42 by loamar            #+#    #+#             */
/*   Updated: 2021/03/25 21:50:42 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"
//de la liste
static t_list 		*check_exec(t_msh *msh, t_list *cmd, char **env)
{
	if (cmd->token != CMD)
	{
		return_error(msh, cmd->content, "syntax error near unexpected token");
		return (NULL);
	}
	// cmd = handler_dollar_env(msh, cmd);
	// if (ft_handler_builtins(msh, cmd, env) != ERROR)
	// 	return (SUCCESS);
	return (cmd);
}

// static int	check_flag(t_msh *msh, t_list *element, int pipe)
// {
// 	struct stat	f;
// 	int			flag;
//
// 	if (lstat(element->content, &f) != -1)
// 	{
// 		flag = f.st_mode & S_IFMT;
// 		if (flag == S_IFDIR && (args[0][ft_strlen(args[0]) - 1] == '/'
// 				|| ft_strnequ(args[0], "./", 2)))
// 			return (return_error(args[0], ": Is a directory\n", 0, 126));
// 		else if ((ft_strnequ(args[0], "./", 2) || ft_strnequ(args[0], "/", 1))
// 			&& (f.st_mode & S_IXUSR) && (f.st_mode & S_IRUSR))
// 			return (run(args, ft_strdup(args[0]), pipe));
// 		else if (flag != S_IXUSR && flag != S_IRUSR
// 			&& flag != S_IFDIR && flag != S_IFLNK)
// 			return (return_error(args[0], ": Permission denied\n", 0, 126));
// 	}
// 	else if (ft_strnequ(args[0], "./", 2) || args[0][0] == '/')
// 	{
// 		return (return_error(args[0], ": No such file or directory\n", 0, 127));
// 	}
// 	return (return_error(args[0], ": command not found\n", 0, 127));
// }

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
		global_sign_info = WTERMSIG(child_status);
	}
	if (WIFEXITED(child_status))
		global_return = child_status;
	global_sign_info = WEXITSTATUS(child_status);
}

int 	exec_cmd(t_msh *msh, t_list *cmd, char **env)
{
	char 	*exec_path;
	int 	count;

	global_error = SUCCESS;
	exec_path = NULL;
	if (ft_handler_builtins(msh, cmd, env) == ERROR_BUILTINS)
	{
		if (cmd == NULL)
			return (ERROR);
		exec_path = get_exec_path(msh, cmd->content);
		count = -1;
		if (msh->utils->pipe == 0)
			global_pid = fork();
		if (global_pid < 0)
		{
			global_error = ERROR;
			return (return_error(msh, "execve", "failed to create a new process."));
		}
		else if (global_pid == 0)
			child_process(msh, cmd, env, exec_path);
		else
			parent_process(msh, cmd);
	}
	if (exec_path)
		free(exec_path);
	if (global_error == ERROR)
		return (ERROR);
	return (SUCCESS);
}

// int 	exec_cmd(t_msh *msh, t_list *cmd, char **env)
// {
// 	int 	count;
// 	char 	*exec_path;
// 	char 	*tmp;
// 	int 	ret;
//
// 	ret = 0;
// 	global_pid = 0;
// 	cmd = (check_exec(msh, cmd, env));
// 	if (cmd == NULL)
// 		return (ERROR);
// 	count = -1;
// 	exec_path = NULL;
// 	global_pid = fork();
// 	if (global_pid < 0)
// 		return_error(msh, cmd->content, NULL);
// 	else if (global_pid == 0)
// 	{
// 		while (msh->utils->path[++count])
// 		{
// 			ret = 0;
// 			tmp = ft_strjoin(msh->utils->path[count], "/");
// 			exec_path = ft_strjoin(tmp, cmd->content);
// 			free(tmp);
// 			cmd->tab_args[0] = ft_strdup(exec_path);
// 			printf("=====================\n");
// 			execve(exec_path, cmd->tab_args, env);
// 			printf("=====================\n");
// 		}
// 		free(exec_path);
// 	}
// 	else
// 		wait(NULL);
// 	return (SUCCESS);
// }
