/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:16:20 by loamar            #+#    #+#             */
/*   Updated: 2021/04/15 00:36:53 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int		get_type_redir(char *content)
{
	if (!content)
		return (ERROR);
	if (ft_strcmp(content, "<") == 0)
		return (CHEVRONL);
	else if (ft_strcmp(content, ">") == 0)
		return (CHEVRONR);
	else if (ft_strcmp(content, ">>") == 0)
		return (CHEVROND);
	else
		return (ERROR);
}

int				return_redir_error(t_list *element, int fd, int i)
{
	char	*join;

	join = ft_strjoin(element->tab_args[i], ": ");
	return_error(ERROR_ERRNO, join, NULL, strerror(errno));
	ft_putstr_fd("\n", 2);
	g_error = ERROR;
	free(join);
	return (fd);
}

static t_list	*exec_redirection(t_msh *msh, t_list *element, int fd,
char **env)
{
	int				child_status;

	child_status = 0;
	if (fork() == 0)
	{
		dup2(fd, msh->utils->redirection);
		close(fd);
		exec_cmd(msh, element->previous, env, 0);
		element = element->next;
		exit(g_sign_info);
	}
	else
	{
		wait(&child_status);
		g_sign_info = WEXITSTATUS(child_status);
	}
	return (element);
}

static	int		check_next(t_list *element)
{
	if (!element->next->next)
	{
		error_cmd(element->next);
		return (-1);
	}
	return (0);
}

t_list			*redirections(t_msh *msh, t_list *element, char **env)
{
	int				fd;
	int				type;

	type = 0;
	msh->utils->redirection = 1;
	if (check_next(element) == -1)
		return (NULL);
	if (element->next && element->next->token == SEPARATOR)
		type = get_type_redir(element->next->content);
	if (type == ERROR)
		return (NULL);
	if (!element->next->next && element->next->next->token != CMD)
	{
		error_cmd(element->next);
		return (NULL);
	}
	if (element->next && type == CHEVRONL)
		msh->utils->redirection = 0;
	element = element->next;
	fd = create_file(element->next, type);
	if (fd == ERROR)
		return (NULL);
	return (exec_redirection(msh, element, fd, env));
}
