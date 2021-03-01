/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 07:42:36 by loamar            #+#    #+#             */
/*   Updated: 2021/03/01 14:28:33 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	ft_pipe(t_msh *msh, t_list *element, char **env, int fd)
{
	int 	pipefd[2];
	pid_t 	pid;

	if (pipe(pipefd) == -1)
		return (-1);
	if ((pid = fork()) == 0)
	{
		printf("first check\n");
		close(pipefd[0]);
		close(0);
		dup(fd); // ?
		close(fd); // ?
		if (msh->utils->multi_pipe == 1)
		{
			printf("check\n");
			close(1);
			dup(pipefd[1]);
			close(pipefd[1]);
		}
		printf("check 0\n");
		exec_cmd(msh, element, env);
		exit(1);
	}
	else if (pid < 0)
	{
		printf("check 1\n");
		close(pipefd[0]);
		close(0);
		close(fd);
		return (-1);
	}
	printf("check 2\n");
	wait(&pid);
	close(fd);
	close(pipefd[1]);
	return (pipefd[0]);
}
