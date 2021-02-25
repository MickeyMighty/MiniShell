/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 07:42:36 by loamar            #+#    #+#             */
/*   Updated: 2021/02/25 15:53:57 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	ft_pipe(t_msh *msh, t_list *element, char **env)
{
	int 	pipefd[2];
	int 	pid;
	char 	*buffer;

	if (pipe(pipefd) == -1)
		return (-1);
	if ((pid = fork()) < 0)
		return (-1);
	if (pid == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		exec_cmd(msh, element->next->next, env);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
 		close(pipefd[1]);
		exec_cmd(msh, element, env);
 		wait(NULL);
	}
	return (0);
}
