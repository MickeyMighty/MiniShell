/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:42 by loamar            #+#    #+#             */
/*   Updated: 2021/03/22 00:34:49 by loamar           ###   ########.fr       */
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

static	void 	child_process(t_msh *msh, t_list *cmd, char **env)
{
	char 	*exec_path;
	char 	*tmp;


	exec_path = NULL;
	tmp = ft_strjoin(msh->utils->path[count], "/");
	exec_path = ft_strjoin(tmp, cmd->content);
	free(tmp);
	cmd->tab_args[0] = ft_strdup(exec_path);
	ret = execve(exec_path, cmd->tab_args, env);
	free(exec_path);
	exit(ret);
}

static	void 	parent_process(t_msh *msh, t_list *cmd, int pid)
{
	int 	child_status;

	child_status = 0;
	signal(SIGINT, SIGQUIT);
	wait(&child_status);
	if (WIFSIGNALED(child_status))
	{
		ft_putstr_fd("\n", 2);
		global_sign_info = WTERMSIG(child_status);
	}
	if (WIFEXITED(child_status))
		global_return = child_status;
	global_sign_info = WEXITSTATUS(chils_status);
	(void)child_pid;
	(void)info;
}

int 	exec_cmd(t_msh *msh, t_list *cmd, char **env)
{
	int 	count;
	int 	pid;

	ret = 0;
	cmd = (check_exec(msh, cmd, env));
	if (cmd == NULL)
		return (ERROR);
	count = -1;
	pid = fork();
	if (pid < 0)
		return (return_error(NULL, NULL));
	else if (pid == 0)
		child_process(msh, cmd, env);
	else
		parent_process(msh, cmd, pid)
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
// 	cmd = (check_exec(msh, cmd, env));
// 	if (cmd == NULL)
// 		return (ERROR);
// 	count = -1;
// 	exec_path = NULL;
// 	global_pid = fork();
// 	if (global_pid < 0)
// 		return (handler_error(msh, NULL));
// 	else if (global_pid == 0)
// 	{
// 		while (msh->utils->path[++count])
// 		{
// 			ret = 0;
// 			tmp = ft_strjoin(msh->utils->path[count], "/");
// 			exec_path = ft_strjoin(tmp, cmd->content);
// 			free(tmp);
// 			cmd->tab_args[0] = ft_strdup(exec_path);
// 			execve(exec_path, cmd->tab_args, env);
// 		}
// 		free(exec_path);
// 	}
// 	else
// 		wait(NULL);
// 	return (SUCCESS);
// }
