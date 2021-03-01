/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 07:42:36 by loamar            #+#    #+#             */
/*   Updated: 2021/03/01 17:24:50 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	ft_pipe(t_msh *msh, t_list *element, char **env, int backup_fd)
{
	int 	pipefd[2];
	pid_t 	pid;

	if (pipe(pipefd) == -1)
		return (-1);
	pid = fork();
	if (pid < 0)
	{
		printf("check 1\n");
		close(pipefd[0]);
		close(pipefd[1]);
		close(backup_fd);
		return (-1);
	}
	if (pid == 0)
	{
		printf("first check\n");
		// close(pipefd[0]);
		// close(0);
		dup2(backup_fd, 0); // ?
		// close(backup_fd); // ?
		// if (element->next->next
		// && get_value_sep(element->next->next->next->content) == PIPE)
		if (element->next->next != NULL)
			dup2(pipefd[1], 1);
		close(pipefd[0]);
		exec_cmd(msh, element, env);
			// close(1);
			// dup(pipefd[1]);
			// close(pipefd[1]);
		printf("check 0\n");
		exit(1);
	}
	else
	{
		printf("check 2\n");
		wait(NULL);
		// close(backup_fd);
		close(pipefd[1]);
		backup_fd = pipefd[0];
	}
	return (backup_fd);
}
