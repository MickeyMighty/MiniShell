/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:04:49 by loamar            #+#    #+#             */
/*   Updated: 2021/03/30 18:52:03 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int			ft_handler_builtins(t_msh *msh, t_list *element, char **env)
{
	size_t	i;
	size_t	len;

	i = -1;
	len = ft_strlen(element->content);
	while (++i < len)
		element->content[i] = ft_tolower(element->content[i]);
	if (ft_strncmp(element->content, "echo", len) == 0)
		return (my_echo(msh, element));
	else if (ft_strncmp(element->content, "cd", len) == 0)
		return (my_cd(msh, element));
	else if (ft_strncmp(element->content, "pwd", len) == 0)
		return (my_pwd(msh));
	else if (ft_strncmp(element->content, "export", len) == 0)
		return (my_export(msh, element));
	else if (ft_strncmp(element->content, "env", len) == 0)
		return (my_env(msh, element));
	else if (ft_strncmp(element->content, "unset", len) == 0)
		return (my_unset(msh, element));
	else if (ft_strncmp(element->content, "exit", len) == 0)
		return (my_exit(msh, element));
	else
		return (ERROR_BUILTINS);
}
