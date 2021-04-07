/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 07:42:13 by loamar            #+#    #+#             */
/*   Updated: 2021/04/07 13:04:37 by lorenzoamar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int			fd_simple_redirection_right(t_list *element)
{
	int				i;
	int				fd;

	i = 1;
	if (element->content)
	{
		fd = open(element->content, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd == ERROR)
			return (return_redir_error(element, fd, i));
		while (element->tab_args[i])
		{
			fd = open(element->tab_args[i], O_CREAT | O_RDWR | O_TRUNC, 0644);
			if (fd == ERROR)
				return (return_redir_error(element, fd, i));
			i++;
		}
		return (fd);
	}
	return (-1);
}

static int			fd_double_redirection_right(t_list *element)
{
	int				i;
	int				fd;

	i = 1;
	if (element->content)
	{
		fd = open(element->content, O_CREAT | O_RDWR | O_APPEND, 0644);
		if (fd == ERROR)
			return (return_redir_error(element, fd, i));
		while (element->tab_args[i])
		{
			fd = open(element->tab_args[i], O_CREAT | O_RDWR | O_APPEND, 0644);
			if (fd == ERROR)
				return (return_redir_error(element, fd, i));
			i++;
		}
		return (fd);
	}
	return (-1);
}

static int			fd_simple_redirection_left(t_list *element)
{
	int				i;
	int				fd;

	i = 1;
	if (element->content)
	{
		fd = open(element->content, O_RDONLY);
		if (fd == ERROR)
			return (return_redir_error(element, fd, i));
		while (element->tab_args[i])
		{
			fd = open(element->tab_args[i], O_RDONLY);
			if (fd == ERROR)
				return (return_redir_error(element, fd, i));
			i++;
		}
		return (fd);
	}
	return (-1);
}

int					create_file(t_list *element, int type)
{
	int				fd;

	fd = 0;
	if (type == CHEVRONR)
		fd = fd_simple_redirection_right(element);
	else if (type == CHEVROND)
		fd = fd_double_redirection_right(element);
	else if (type == CHEVRONL)
		fd = fd_simple_redirection_left(element);
	return (fd);
}
