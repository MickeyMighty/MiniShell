/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 07:42:36 by loamar            #+#    #+#             */
/*   Updated: 2021/02/28 13:42:17 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	ft_pipe(t_msh *msh, t_list *element, char **env)
{
	int 	pipefd[2];
	pid_t 	pid;
	char 	*buffer;

	printf("previous -> %s\n", element->previous->content);
	printf("now -> %s\n", element->content);
	printf("next -> %s\n", element->next->content);
	// if (pipe(pipefd) == -1)
		// return (-1);
	pipe(pipefd);
	if ((pid = fork()) == 0)
	{
		if (pipefd[1] > 0)
			close(pipefd[1]);
		dup2(pipefd[0], STDIN);
		close(pipefd[0]);
		exec_cmd(msh, element->next, env);
		return (1);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT);
 		close(pipefd[1]);
		exec_cmd(msh, element->previous, env);
 		// wait(NULL);
		return (2);
	}
	return (0);
}
