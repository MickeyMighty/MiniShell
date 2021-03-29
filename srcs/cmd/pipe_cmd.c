/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 07:42:36 by loamar            #+#    #+#             */
/*   Updated: 2021/03/27 15:43:24 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static	int		bad_fork(int *pipefd, int backup_fd)
{
	close(pipefd[0]);
	close(pipefd[1]);
	close(backup_fd);
	return (-1);
}

int				ft_pipe(t_msh *msh, t_list *element, char **env, int backup_fd)
{
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		return (-1);
	global_pid = fork();
	if (global_pid < 0)
		return (bad_fork(pipefd, backup_fd));
	if (global_pid == 0)
	{
		dup2(backup_fd, 0);
		if (element->next != NULL && element->next->next != NULL)
			dup2(pipefd[1], 1);
		close(pipefd[0]);
		exec_cmd(msh, element, env);
		exit(1);
	}
	else
	{
		wait(&global_pid);
		close(pipefd[1]);
		backup_fd = pipefd[0];
	}
	return (backup_fd);
}
