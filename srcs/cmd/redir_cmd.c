/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:16:20 by loamar            #+#    #+#             */
/*   Updated: 2021/03/26 17:06:48 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int          get_type_redir(char *content)
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

int             return_redir_error(t_msh *msh, t_list *element, int fd, int i)
{
    char    *join;

    join = ft_strjoin(element->tab_args[i], ": ");
    return_error(msh, join, strerror(errno));
    ft_putstr_fd("\n", 2);
    global_error = ERROR_REDIRECTION;
    free(join);
    return (fd);
}

static t_list     *exec_redirection(t_msh *msh, int fd, int redirection)
{
	int				child_status;

	child_status = 0;
	if (fork() == 0)
	{
		dup2(fd, redirection);
		close(fd);
        if (element->next->next)
		      element = exec_cmd_handler(msh, element);
        else
        {
            exec_cmd(msh, element->previous, env);
            element = element->next;
        }
		exit(global_info_ret);
	}
	else
	{
		wait(&child_status);
		global_info_ret = WEXITSTATUS(child_status);
	}
    return (element);
}

t_list				*redirections(t_msh *msh, t_list *element)
{
	int				fd;
    int             type;
	int				redirection;

	redirection = 1;
    if (element->next && element->next->token == SEPARATOR)
        type = get_type_redir(element->next->content)
    if (type == ERROR)
        return (NULL);
    if (!element->next->next && element->next->next->token != CMD)
    {
        error_cmd(t_msh, element->next);
        return (NULL);
    }
    if (element->next && type == CHEVRONL)
		redirection = 0;
    element = element->next;
	fd = create_file(element->next, type);
	if (fd == ERROR)
		return (NULL);
	exec_redirection(msh, element, fd, redirection);
}
