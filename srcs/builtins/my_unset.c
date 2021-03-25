/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:56:45 by loamar            #+#    #+#             */
/*   Updated: 2021/03/25 22:56:49 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

// static char	**remove_env(ssize_t index)
// {
// 	char	*tmp;
// 	size_t	i;
// 	size_t	size;
//
// 	i = index;
// 	size = get_envs_count();
// 	while (g_envs[i + 1])
// 	{
// 		tmp = ft_strdup(g_envs[i + 1]);
// 		free(g_envs[i]);
// 		g_envs[i] = tmp;
// 		i++;
// 	}
// 	return (realloc_envs((size - 1)));
// }
//
// int 	my_unset(t_msh *msh, t_element *element)
// {
// 	size_t	i;
// 	ssize_t	index;
//
// 	global_status = 0;
// 	if (!element->tab_args[1])
// 		return (SUCCESS);
// 	i = 0;
// 	while (element->tab_args[++i])
// 	{
// 		index = find_env(args[i]);
// 		if (index != -1)
// 		{
// 			if (g_envs[index])
// 			g_envs = remove_env(index);
// 		}
// 		else
// 		{
// 			ft_putstr_fd("minishell: unset: `", 2);
// 			ft_putstr_fd(element->tab_args[i], 2);
// 			ft_putstr_fd("': not a valid identifier\n", 2);
// 			global_status = 1;
// 		}
// 	}
// 	return (1);
// }
