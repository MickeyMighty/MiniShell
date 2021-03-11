/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:42 by loamar            #+#    #+#             */
/*   Updated: 2021/03/11 14:17:02 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"
//de la liste
static t_list 		*check_exec(t_msh *msh, t_list *cmd, char **env)
{
	if (cmd->token != CMD)
		handler_error(msh, "syntax error near unexpected token \';\'"); // a changer
	cmd = handler_dollar_env(msh, cmd);
	// if (ft_handler_builtins(msh, cmd, env) != ERROR)
	// 	return (SUCCESS);
	return (cmd);
}

int 	exec_cmd(t_msh *msh, t_list *cmd, char **env)
{
	int 	count;
	char 	*exec_path;
	char 	*tmp;
	int 	ret;

	ret = 0;
	cmd = (check_exec(msh, cmd, env));
	count = -1;
	exec_path = NULL;
	msh->utils->pid = fork();
	if (msh->utils->pid < 0)
		return (handler_error(msh, NULL));
	else if (msh->utils->pid == 0)
	{
		while (msh->utils->path[++count])
		{
			ret = 0;
			tmp = ft_strjoin(msh->utils->path[count], "/");
			exec_path = ft_strjoin(tmp, cmd->content);
			free(tmp);
			cmd->tab_args[0] = ft_strdup(exec_path);
			// execve(exec_path, cmd->tab_args, env);
			// printf("ret = %d\n", ret);
			ret = execve(exec_path, cmd->tab_args, env);
			// printf("ret = %d\n", ret);
			// exit(ret); // chek the signal
			// if (ret == -1)
			// 	handler_error(msh, "command not found.");
		}
		free(exec_path);
	}
	else
		wait(NULL);
	return (SUCCESS);
}
