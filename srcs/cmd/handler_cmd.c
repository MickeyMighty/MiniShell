/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:33 by loamar            #+#    #+#             */
/*   Updated: 2021/03/25 23:17:27 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 		error_cmd(t_msh *msh, t_list *element)
{
	if ((ft_strcmp(element->content, "|") == 0)
	|| (ft_strcmp(element->content, "&") == 0)
	|| (ft_strcmp(element->content, ";") == 0))
	{
		global_error = ERROR_CMD;
		return (return_error(msh, element->content,
		"syntax error near unexpected token"));
	}
	else if ((ft_strcmp(element->content, ">") == 0)
	|| (ft_strcmp(element->content, ">>") == 0)
	|| (ft_strcmp(element->content, "<") == 0)
	|| (ft_strcmp(element->content, "!") == 0))
	{
		global_error = ERROR_CMD;
		return (return_error(msh, "newline",
			"syntax error near unexpected token"));
	}
	return (ERROR);
}

int 			get_value_sep(char *str)
{
	if (ft_strcmp(str, "|") == 0)
		return (PIPE);
	else if (ft_strcmp(str, "<") == 0 || ft_strcmp(str, ">") == 0
	|| ft_strcmp(str, ">>") == 0)
		return (REDIR);
	else if (ft_strcmp(str, ";") == 0)
		return (SEMICOLON);
	else
		return (0);
}

static t_list 	*multi_pipe(t_msh *msh, t_list *element, char **env)
{
	int		backup_fd;

	msh->utils->pipe = 1;
	msh->utils->multi_pipe = 0;
	backup_fd = 0;
	backup_fd = dup2(backup_fd, 0);
	while (element)
	{
		if (element->next
	 	&& (get_value_sep(element->next->content) == PIPE))
		{
			if (!element->next->next)
			{
				global_error_msg = ERROR;
				return (NULL);
			}
			backup_fd = ft_pipe(msh, element, env, backup_fd);
			element = element->next->next;
			backup_fd = ft_pipe(msh, element, env, backup_fd);
		}
		if (element->next
		&& (get_value_sep(element->next->content) != PIPE))
		{
			element = element->next;
			close(backup_fd);
			return (element);
		}
		else if (!element->next)
		{
			close(backup_fd);
			return (element);
		}
	}
	close(backup_fd);
	return (element);
}

int 	sort_cmd(t_msh *msh, t_list *element, char **env)
{
	t_list	*tmp;

	while (element != NULL)
	{
		msh->utils->pipe = 0;
		if (element->token == CMD)
			element = check_block_cmd(msh, element);
		if (global_error_msg == ERROR)
			return (return_error(msh, NULL, "syntax error multiligne."));
		if (element->next != NULL && element->next->token == SEPARATOR)
		{
			if (get_value_sep(element->next->content) == PIPE)
				element = multi_pipe(msh, element, env);
			else if (get_value_sep(element->next->content) == REDIR)
				element = ft_reddirection(msh, element);
			else if (get_value_sep(element->next->content) == SEMICOLON)
			{
				exec_cmd(msh, element, env);
				ft_putstr_fd("\n", 1);
				element = element->next;
			}
			if (global_error_msg == ERROR)
				return (return_error(msh, NULL, "syntax error multiligne."));
		}
		else
			exec_cmd(msh, element, env);
		if (element != NULL)
			element = element->next;
	}
	return (1);
}

int 	handler_cmd(t_msh *msh, char **env)
{
	int		ret;
	t_list 	*tmp;
	t_list 	*element;

	element = msh->lair_list->start;
	printf("handler cmd start\n");
	if (sort_cmd(msh, element, env) == ERROR)
		return (ERROR);
	printf("handler cmd end\n");
	return (SUCCESS);
}
