/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:42 by loamar            #+#    #+#             */
/*   Updated: 2021/02/15 13:12:40 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	exec_cmd(t_msh *msh, t_list *cmd, char **env)
{
	int 	count;
	char 	*exec_path;
	char	**exec_args;

	count = -1;
	exec_path = NULL;
	msh->utils->pid = fork();
	if (msh->utils->pid < 0)
		return (handler_error(msh));
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
	return (-1);
}

int		handler_exec_cmd(t_msh *msh, int (*exec)(t_list))
{
	;
}
