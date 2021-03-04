/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:42 by loamar            #+#    #+#             */
/*   Updated: 2021/03/04 10:37:54 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	exec_cmd(t_msh *msh, t_list *cmd, char **env)
{
	int 	count;
	char 	*exec_path;
	char	**exec_args;

	if (cmd->token != CMD)
		handler_error(msh, "Bad cmd.\n"); // a changer
	if (ft_handler_builtins(msh, cmd, env) == ERROR)
	{
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
	return (SUCCESS);
}
