/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:07:43 by loamar            #+#    #+#             */
/*   Updated: 2020/12/07 03:53:58 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	exec_cmd(t_data *data, t_prompt_list *prompt_list, t_lair_list *lair_list)
{
	pid_t 	pid;
	pid_t 	wpid;
	int 	status;

	pid = 0;
	wpid = 0;
	status = 0;
	pid = fork();
	// return (0); // besoin de return errno
	if (pid == -1)
		perror("fork");
	else if (pid > 0)
	{
		printf("pid > 0\n");
		wpid = waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		if (execve(data->prompt_data[0], data->prompt_data, NULL) == -1)
			perror("shell");
		printf("-> %s\n", data->prompt_data[0]);
		exit(EXIT_FAILURE);
		// return (0);
	}
	printf("ok\n");
	exit(0);
	return (1);
}
