/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:42 by loamar            #+#    #+#             */
/*   Updated: 2021/01/12 16:39:46 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static char    **ft_exec_args(t_msh *msh, t_list *cmd, char *cmd_path)
{
	t_list 	*tmp;
	int 	pos;

	pos = 1;
	tmp = cmd;
	cmd = cmd->next;
	msh->utils->size_opt_arg = 0;
	while (cmd != NULL && (cmd->token == OPTION || cmd->token == ARGS))
	{
		cmd = cmd->next;
		msh->utils->size_opt_arg++;
	}
	cmd = tmp;
	if (!(msh->utils->tab_args = malloc(sizeof(char *) * (msh->utils->size_opt_arg + 2))))
		return (0);
	while (pos <= msh->utils->size_opt_arg)
	{
		cmd = cmd->next;
		msh->utils->tab_args[pos] = cmd->content;
		pos++;
	}
	msh->utils->tab_args[0] = cmd_path;
    msh->utils->tab_args[msh->utils->size_opt_arg + 1] = NULL;
	// printf("tab[%s]\n", msh->utils->tab_args[0]);
	// printf("tab[%s]\n", msh->utils->tab_args[1]);
	// printf("tab[%s]\n", msh->utils->tab_args[2]);
	// exit(0);
    return (msh->utils->tab_args);
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
			exec_args = ft_exec_args(msh, cmd, exec_path);
			// printf("exec_path => %s\n", exec_path);
			execve(exec_path, exec_args, env);
		}
	}
	else
		wait(NULL);
	return (-1);
}
