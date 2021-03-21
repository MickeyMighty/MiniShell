/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:04:49 by loamar            #+#    #+#             */
/*   Updated: 2021/03/20 20:17:59 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/libshell.h"

static int	ft_built_in_check(t_msh *msh, t_list *element, char **env)
{
	size_t	i;
	size_t	len;

	i = -1;
	len = ft_strlen(element->content);
	// faire pour les ""
	while (++i < len)
		element->content[i] = ft_tolower(element->content[i]);
	if (ft_strncmp(element->content, "echo", len) == 0)
		return (ft_my_echo(msh, element));
	else if (ft_strncmp(element->content, "cd", len) == 0)
		return (ft_my_cd(msh, element));
	else if (ft_strncmp(element->content, "pwd", len) == 0)
		return (ft_my_pwd(msh, element));
	else if (ft_strncmp(element->content, "export", len) == 0)
		return (ft_my_export(msh, element));
	else if (ft_strncmp(element->content, "env", len) == 0)
		return (ft_my_env(msh, element));
	else if (ft_strncmp(element->content, "unset", len) == 0)
		return (ft_my_unset(msh, element));
	else if (ft_strncmp(element->content, "exit", len) == 0)
		return (ft_my_exit(msh, element));
	else
		return (ERROR);
}
// // detect args & options
// // exec cmd + args & options
//
int 		ft_handler_builtins(t_msh *msh, t_list *element, char **env)
{
	if (ft_built_in_check(msh, element, env) == SUCCESS)
		return (SUCCESS);
	else
		return (ERROR);
	//builtin executiuon by ptr_func_tab
}
