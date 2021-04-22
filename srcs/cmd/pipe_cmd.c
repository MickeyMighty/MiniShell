/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 07:42:36 by loamar            #+#    #+#             */
/*   Updated: 2021/04/22 23:21:20 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static	t_list	*return_multi_pipe(t_msh *msh, t_list *element, char **env)
{
	if (element->next && (get_value_sep(element->next->content) == PIPE))
	{
		if (!element->next->next)
		{
			g_error_msg(SET, ERROR);
			return (NULL);
		}
		msh->utils->backup_fd = ft_pipe(msh, element, env,
		msh->utils->backup_fd);
		element = element->next->next;
		if (element->token == CMD)
			element = check_block_cmd(msh, element);
		msh->utils->backup_fd = ft_pipe(msh, element, env,
		msh->utils->backup_fd);
	}
	else if (element->next && (get_value_sep(element->next->content) == REDIR))
		element = redirections(msh, element, env);
	return (element);
}

t_list			*multi_pipe(t_msh *msh, t_list *element, char **env)
{
	msh->utils->backup_fd = 0;
	msh->utils->backup_fd = dup(0);
	while (element)
	{
		element = return_multi_pipe(msh, element, env);
		if (g_error_msg(GET, 0) == ERROR)
			return (NULL);
		if (element->next
		&& (get_value_sep(element->next->content) != PIPE))
		{
			element = element->next;
			return (element);
		}
		else if (!element->next)
			return (element);
	}
	close(msh->utils->backup_fd);
	return (element);
}

static	void	pipe_child(t_list *element, int pipefd[2], int backup_fd)
{
	close(pipefd[0]);
	close(0);
	dup(backup_fd);
	close(backup_fd);
	if (element->next != NULL && element->next->next != NULL
	&& (get_value_sep(element->next->content) == PIPE))
	{
		close(1);
		dup(pipefd[1]);
		close(pipefd[1]);
	}
}

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
	pid_t	pid;

	pid = 0;
	pipefd[0] = -1;
	pipefd[1] = -1;
	if (pipe(pipefd) == -1)
		return (-1);
	g_pid(SET, fork());
	if (g_pid(GET, 0) < 0)
		return (bad_fork(pipefd, backup_fd));
	if (g_pid(GET, 0) == 0)
	{
		pipe_child(element, pipefd, backup_fd);
		exec_cmd(msh, element, env, 1);
		free_all(msh, EXIT);
		exit(g_status);
	}
	pid = g_pid(GET, 0);
	wait(&pid);
	g_pid(SET, pid);
	status_child();
	close(backup_fd);
	close(pipefd[1]);
	return (pipefd[0]);
}
