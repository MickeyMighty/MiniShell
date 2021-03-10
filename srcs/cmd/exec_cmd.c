/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:42 by loamar            #+#    #+#             */
/*   Updated: 2021/03/10 23:48:44 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	check_exec(t_msh *msh, t_list *cmd, char **env)
{
	if (cmd->token != CMD)
		handler_error(msh, "syntax error near unexpected token \';\'"); // a changer
	if (cmd->dollar == 1 && cmd->quote != 1)
		cmd->content = handler_dollar_env(msh, cmd);
	if (ft_handler_builtins(msh, cmd, env) != ERROR)
		return (SUCCESS);
	return (ERROR);
}

int 	exec_cmd(t_msh *msh, t_list *cmd, char **env)
{
	int 	count;
	char 	*exec_path;
	char	**exec_args;

	if (check_exec(msh, cmd, env) == SUCCESS)
		return (SUCCESS);
	count = -1;
	exec_path = NULL;
	msh->utils->pid = fork();
	if (msh->utils->pid < 0)
		return (handler_error(msh, NULL));
	else if (msh->utils->pid == 0)
	{
		while (msh->utils->path[++count])
		{
			exec_path = ft_strjoin(msh->utils->path[count], "/");
			exec_path = ft_strjoin(exec_path, cmd->content);
			cmd->tab_args[0] = ft_strdup(exec_path);
			execve(exec_path, cmd->tab_args, env);
		}
	}
	else
		wait(NULL);
	return (SUCCESS);
}
