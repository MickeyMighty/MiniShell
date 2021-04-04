/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:33 by loamar            #+#    #+#             */
/*   Updated: 2021/04/04 01:08:00 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int				error_cmd(t_msh *msh, t_list *element)
{
	if ((ft_strcmp(element->content, "|") == 0)
	|| (ft_strcmp(element->content, "&") == 0)
	|| (ft_strcmp(element->content, ";") == 0))
	{
		global_error = ERROR;
		global_status = 2;
		return (return_error(ERROR_CMD, element->content, NULL,
		"syntax error near unexpected token"));
	}
	else if ((ft_strcmp(element->content, ">") == 0)
	|| (ft_strcmp(element->content, ">>") == 0)
	|| (ft_strcmp(element->content, "<") == 0)
	|| (ft_strcmp(element->content, "!") == 0))
	{
		global_error = ERROR;
		global_status = 2;
		return (return_error(ERROR_TOKEN, "newline", NULL,
		"syntax error near unexpected token"));
	}
	return (ERROR);
}

static	t_list	*return_multi_pipe(t_msh *msh, t_list *element, char **env)
{
	if (element->next && (get_value_sep(element->next->content) == PIPE))
	{
		if (!element->next->next)
		{
			global_error_msg = ERROR;
			return (NULL);
		}
		msh->utils->backup_fd =
		ft_pipe(msh, element, env, msh->utils->backup_fd);
		element = element->next->next;
		msh->utils->backup_fd = ft_pipe(msh, element, env,
		msh->utils->backup_fd);
	}
	else if (element->next && (get_value_sep(element->next->content) == REDIR))
		element = redirections(msh, element, env);
	return (element);
}

static	t_list	*multi_pipe(t_msh *msh, t_list *element, char **env)
{
	msh->utils->backup_fd = 0;
	msh->utils->backup_fd = dup2(msh->utils->backup_fd, 0);
	while (element)
	{
		element = return_multi_pipe(msh, element, env);
		if (global_error_msg == ERROR)
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
	return (element);
}

static	t_list	*sort_cmd(t_msh *msh, t_list *element, char **env)
{
	if (get_value_sep(element->next->content) == PIPE)
		element = multi_pipe(msh, element, env);
	else if (get_value_sep(element->next->content) == REDIR)
	{
		if (element->next->next && element->next->next->next
		&& (get_value_sep(element->next->content) == PIPE))
		{
			msh->utils->pipe = 1;
			msh->utils->multi_pipe = 0;
			element = multi_pipe(msh, element, env);
		}
		else
			element = redirections(msh, element, env);
	}
	else if (get_value_sep(element->next->content) == SEMICOLON)
	{
		exec_cmd(msh, element, env);
		element = element->next;
	}
	return (element);
}

int				handler_cmd(t_msh *msh, char **env)
{
	t_list	*tmp;
	t_list	*element;

	global_error_msg = 0;
	element = msh->lair_list->start;
	while (element != NULL)
	{
		msh->utils->pipe = 0;
		if (element->token == CMD)
			element = check_block_cmd(msh, element);
		msh->utils->pos = 0;
		if (global_error_msg == ERROR_MULTI)
			return (return_error(ERROR_MSG, NULL, NULL, "syntax error multiligne."));
		if (element->next != NULL && element->next->token == SEPARATOR)
		{
			element = sort_cmd(msh, element, env);
			if (global_error_msg == ERROR_MULTI)
				return (return_error(ERROR_MSG, NULL, NULL, "syntax error multiligne."));
		}
		else
			exec_cmd(msh, element, env);
		if (element)
			element = element->next;
	}
	return (SUCCESS);
}
