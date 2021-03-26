/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 07:42:13 by loamar            #+#    #+#             */
/*   Updated: 2021/03/26 14:09:11 by loamar           ###   ########.fr       */
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
		return(return_redir_error(msh, element, fd));
		while (element->tab_args[i])
		{
			fd = open(element->tab_args[i], O_CREAT | O_RDWR | O_TRUNC, 0644);
			if (fd == ERROR)
			return(return_redir_error(msh, element, fd));
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
		return(return_redir_error(msh, element, fd));
		while (element->tab_args[i])
		{
			fd = open(element->tab_args[i], O_CREAT | O_RDWR | O_APPEND, 0644);
			if (fd == ERROR)
			return(return_redir_error(msh, element, fd));
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
			return(return_redir_error(msh, element, fd));
		while (element->tab_args[i])
		{
			fd = open(element->tab_args[i], O_RDONLY);
			if (fd == ERROR)
				return(return_redir_error(msh, element, fd));
			i++;
		}
		return (fd);
	}
	return (-1);
}

int					create_file(t_msh *msh, t_list *element, int type)
{
	int				fd;

	if (type == simple_redir_right)
		fd = fd_simple_redirection_right(element->next);
	else if (type == double_redir_right)
		fd = fd_double_redirection_right(element->next);
	else if (type == simple_redir_left)
		fd = fd_simple_redirection_left(element->next);
	return (fd);
}

// int     redirection_left(t_msh *msh, t_list *element)
// {
//     int     ret;
//
//     ret = open(element->content, O_RDONLY);
//     return (ret);
// }
//
// int     redirection_right(t_msh *msh, t_list *element)
// {
//     int     ret;
//
//     ret = open(element->content, O_CREAT |  O_RDWR | O_TRUNC, 0644);
//     return (ret);
// }
//
// int     redirection_double_right(t_msh *msh, t_list *element)
// {
//     int     ret;
//
//     ret = open(element->content, O_CREAT |  O_RDWR | O_APPEND, 0644);
//     return (ret);
// }
//
// int     create_file(t_msh *msh, t_list *element)
// {
//     int     ret;
//
//     printf("redir0\n");
//     if (element->token == CHEVRONL)
//     {
//         printf("redir1\n");
//         ret = redirection_left(msh, element);
//
//     }
//     else if (element->next->token == CHEVRONR)
//     {
//         printf("redir2\n");
//         ret = redirection_right(msh, element);
//
//     }
//     else if (element->next->token == CHEVROND)
//     {
//
//         printf("redir3\n");
//         ret = redirection_double_right(msh, element);
//     }
//     printf("redir4\n");
//     return (ret);
// }
//
// t_list    *redirection(t_msh *msh, t_list *element)
// {
//     int     fd;
//     t_list  *tmp;
//
//     tmp = element;
//     if (element->token == CMD)
//     {
//         element = element->next;
//         if (element->token == SEPARATOR && element->next->token == CMD)
//             element = element->next->next;
//     }
//     fd = create_file(msh, element);
//     element = element->next->next;
//     return (element);
// }
