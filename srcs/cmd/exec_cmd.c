/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:07:43 by loamar            #+#    #+#             */
/*   Updated: 2020/12/11 17:03:40 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

//(void)msh; -> set to mute warning 
int 	exec_cmd(t_msh *msh)
{
	pid_t 	pid;
	pid_t 	wpid;
	int 	status;

	(void)msh;
	pid = 0;
	wpid = 0;
	status = 0;
	pid = fork();
	// // return (0); // besoin de return errno
	// if (pid < 0)
	// {
	// 	printf("ok no\n");
	// 	perror("fork");
	// }
	// else if (pid > 0)
	// {
	// 	// printf("pid > 0\n");
	// 	wpid = waitpid(pid, &status, 0);
	// 	while (wpid <= 0)
	// 		wpid = waitpid(pid, &status, 0);
	// 	kill(pid, SIGTERM);
	// 	if (execve(msh->, msh->, NULL) == -1)
	// 	{
	// 		printf("MAIS WTF\n");
	// 		return (-1);
	// 	}
	// 	// printf("-> %s\n", msh->data->prompt_data[0]);
	// }
	// else
	// {
	// 	// return (0);
	// }
	return (1);
}
