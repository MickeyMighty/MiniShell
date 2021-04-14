/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 07:42:36 by loamar            #+#    #+#             */
/*   Updated: 2021/04/14 16:27:42 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static	t_list	*return_multi_pipe(t_msh *msh, t_list *element, char **env)
{
	if (element->next && (get_value_sep(element->next->content) == PIPE))
	{
		if (!element->next->next)
		{
			g_error_msg = ERROR;
			return (NULL);
		}
		msh->utils->backup_fd =
		ft_pipe(msh, element, env, msh->utils->backup_fd);
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
	msh->utils->backup_fd = dup2(msh->utils->backup_fd, 0);
	while (element)
	{
		element = return_multi_pipe(msh, element, env);
		if (g_error_msg == ERROR)
			return (NULL);
		if (element->next
		&& (get_value_sep(element->next->content) != PIPE))
		{
			element = element->next;
			close(msh->utils->backup_fd);
			return (element);
		}
		else if (!element->next)
		{
			close(msh->utils->backup_fd);
			return (element);
		}
	}
	close(msh->utils->backup_fd);
	free_all(msh, EXIT);
	return (element);
}

static void		status_child(void)
{
	if (WIFEXITED(g_pid))
		g_status = WEXITSTATUS(g_pid);
	if (WIFSIGNALED(g_pid))
	{
		g_status = WTERMSIG(g_pid);
		if (g_status != 131)
			g_status += 128;
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

	if (pipe(pipefd) == -1)
		return (-1);
	g_pid = fork();
	if (g_pid < 0)
		return (bad_fork(pipefd, backup_fd));
	if (g_pid == 0)
	{
		dup2(backup_fd, 0);
		if (element->next != NULL && element->next->next != NULL)
			dup2(pipefd[1], 1);
		close(pipefd[0]);
		exec_cmd(msh, element, env);
		free_all(msh, EXIT);
		exit(g_status);
	}
	else
	{
		wait(&g_pid);
		status_child();
		close(pipefd[1]);
		backup_fd = pipefd[0];
		free_all(msh, EXIT);
	}
	free_all(msh, EXIT);
	return (backup_fd);
}
