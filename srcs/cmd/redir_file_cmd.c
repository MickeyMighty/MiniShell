/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 07:42:13 by loamar            #+#    #+#             */
/*   Updated: 2021/03/27 15:46:03 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int			fd_simple_redirection_right(t_msh *msh, t_list *element)
{
	int				i;
	int				fd;

	i = 1;
	if (element->content)
	{
		fd = open(element->content, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd == ERROR)
			return (return_redir_error(msh, element, fd, i));
		while (element->tab_args[i])
		{
			fd = open(element->tab_args[i], O_CREAT | O_RDWR | O_TRUNC, 0644);
			if (fd == ERROR)
				return (return_redir_error(msh, element, fd, i));
			i++;
		}
		return (fd);
	}
	return (-1);
}

static int			fd_double_redirection_right(t_msh *msh, t_list *element)
{
	int				i;
	int				fd;

	i = 1;
	if (element->content)
	{
		fd = open(element->content, O_CREAT | O_RDWR | O_APPEND, 0644);
		if (fd == ERROR)
			return (return_redir_error(msh, element, fd, i));
		while (element->tab_args[i])
		{
			fd = open(element->tab_args[i], O_CREAT | O_RDWR | O_APPEND, 0644);
			if (fd == ERROR)
				return (return_redir_error(msh, element, fd, i));
			i++;
		}
		return (fd);
	}
	return (-1);
}

static int			fd_simple_redirection_left(t_msh *msh, t_list *element)
{
	int				i;
	int				fd;

	i = 1;
	if (element->content)
	{
		fd = open(element->content, O_RDONLY);
		if (fd == ERROR)
			return (return_redir_error(msh, element, fd, i));
		while (element->tab_args[i])
		{
			fd = open(element->tab_args[i], O_RDONLY);
			if (fd == ERROR)
				return (return_redir_error(msh, element, fd, i));
			i++;
		}
		return (fd);
	}
	return (-1);
}

int					create_file(t_msh *msh, t_list *element, int type)
{
	int				fd;

	if (type == CHEVRONR)
		fd = fd_simple_redirection_right(msh, element);
	else if (type == CHEVROND)
		fd = fd_double_redirection_right(msh, element);
	else if (type == CHEVRONL)
		fd = fd_simple_redirection_left(msh, element);
	return (fd);
}
