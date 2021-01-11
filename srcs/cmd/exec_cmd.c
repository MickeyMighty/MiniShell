/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:07:43 by loamar            #+#    #+#             */
/*   Updated: 2021/01/11 14:47:03 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	exec_cmd(t_msh *msh, t_list *cmd)
{
	int 	count;
	char 	*exec_path;

	printf("exec\n");
	count = 0;
	exec_path = NULL;
	msh->utils->pid = fork();
	if (msh->utils->pid < 0)
		return (handler_error(msh));
	else if (msh->utils->pid == 0)
	{
		while (msh->utils->path[count])
		{
			exec_path = ft_strjoin(msh->utils->path[count], "/");
			exec_path = ft_strjoin(exec_path, cmd->content);
			// exec_path = ft_strjoin(exec_path, );
			execve(exec_path, NULL, NULL);
			count++;

		}
	}
	else
		wait(NULL);
	return (-1);
}
