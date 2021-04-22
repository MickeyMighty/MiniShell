/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:33 by loamar            #+#    #+#             */
/*   Updated: 2021/04/22 22:53:04 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int				error_cmd(t_list *element)
{
	if ((ft_strcmp(element->content, "|") == 0)
	|| (ft_strcmp(element->content, "&") == 0)
	|| (ft_strcmp(element->content, ";") == 0))
	{
		g_error(SET, ERROR);
		g_status = 2;
		return (return_error(ERROR_TOKEN, element->content, NULL,
		"syntax error near unexpected token"));
	}
	else if ((ft_strcmp(element->content, ">") == 0)
	|| (ft_strcmp(element->content, ">>") == 0)
	|| (ft_strcmp(element->content, "<") == 0)
	|| (ft_strcmp(element->content, "!") == 0))
	{
		g_error(SET, ERROR);
		g_status = 2;
		return (return_error(ERROR_TOKEN, "newline", NULL,
		"syntax error near unexpected token"));
	}
	return (ERROR);
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
		exec_cmd(msh, element, env, 0);
		element = element->next;
	}
	return (element);
}

static	int		check_return_error(void)
{
	if (g_error_msg(GET, 0) == ERROR_MULTI)
	{
		return (return_error(ERROR_MSG, NULL, NULL,
		"syntax error multiligne."));
	}
	return (SUCCESS);
}

int				handler_cmd(t_msh *msh, char **env)
{
	t_list	*element;

	g_error_msg(SET, 0);
	element = msh->lair_list->start;
	while (element != NULL)
	{
		msh->utils->no_space = 0;
		msh->utils->pipe = 0;
		if (element->token == CMD)
			element = check_block_cmd(msh, element);
		msh->utils->pos = 0;
		if (check_return_error() == ERROR)
			return (ERROR);
		if (element->next != NULL && element->next->token == SEPARATOR)
		{
			element = sort_cmd(msh, element, env);
			if (check_return_error() == ERROR)
				return (ERROR);
		}
		else
			exec_cmd(msh, element, env, 0);
		if (element)
			element = element->next;
	}
	return (SUCCESS);
}
