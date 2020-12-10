/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:07:43 by loamar            #+#    #+#             */
/*   Updated: 2020/12/10 13:25:41 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	exec_cmd(t_msh *msh)
{
	pid_t 	pid;
	pid_t 	wpid;
	int 	status;

	pid = 0;
	wpid = 0;
	status = 0;
	pid = fork();
	// return (0); // besoin de return errno
	if (pid < 0)
	{
		printf("ok no\n");
		perror("fork");
	}
	else if (pid > 0)
	{
		// printf("pid > 0\n");
		wpid = waitpid(pid, &status, 0);
		while (wpid <= 0)
			wpid = waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
		if (execve(msh->data->prompt_data[0], msh->data->prompt_data, NULL) == -1)
			perror("shell");
		// printf("-> %s\n", msh->data->prompt_data[0]);
		exit(EXIT_FAILURE);
	}
	// else
	// {
	// 	// return (0);
	// }
	return (1);
}
