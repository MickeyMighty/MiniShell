/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:04:49 by loamar            #+#    #+#             */
/*   Updated: 2021/04/07 12:13:24 by lorenzoamar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int			ft_handler_builtins(t_msh *msh, t_list *element)
{
	if (ft_strcmp(element->content, "echo") == 0)
		return (my_echo(msh, element));
	else if (ft_strcmp(element->content, "cd") == 0)
		return (my_cd(msh, element));
	else if (ft_strcmp(element->content, "pwd") == 0)
		return (my_pwd());
	else if (ft_strcmp(element->content, "export") == 0)
		return (my_export(msh, element));
	else if (ft_strcmp(element->content, "env") == 0)
		return (my_env(msh));
	else if (ft_strcmp(element->content, "unset") == 0)
		return (my_unset(msh, element));
	else if (ft_strcmp(element->content, "exit") == 0)
		return (my_exit(msh, element));
	else
		return (ERROR_BUILTINS);
}
