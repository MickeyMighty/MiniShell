/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:07:43 by loamar            #+#    #+#             */
/*   Updated: 2021/01/11 19:15:48 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static char    **ft_exec_args(char *cmd_path, char *arg)
{
    char **cmd_args;
    int i;

    i = 0;
    if (!(cmd_args = malloc(sizeof(char *) * 3)))
        return (NULL);
    while (++i < 3)
    {
        cmd_args[0] = cmd_path;
        cmd_args[1] = arg;
        if (arg == NULL)
            break;
        cmd_args[2] = NULL;
    }
    return (cmd_args);
}

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
			// printf("cmd->content = %s\n", cmd->content);
			exec_path = ft_strjoin(msh->utils->path[count], "/");
			exec_path = ft_strjoin(exec_path, cmd->content);
			exec_args = ft_exec_args(exec_path, NULL);
			// printf("exec_path => %s\n", exec_path);
			execve(exec_path, exec_args, env);
		}
	}
	else
		wait(NULL);
	return (-1);
}
