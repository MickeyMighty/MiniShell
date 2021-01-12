/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:41:31 by tidminta          #+#    #+#             */
/*   Updated: 2021/01/12 16:39:59 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int			ft_my_env(t_env_lair *lst)
{
	t_env_list *env;

	if (!lst)
		return (ERROR);
	env = lst->start;
	while (env->next != NULL)
	{
		ft_putendl_fd(env->content, 1);
		env = env->next;
	}
	return (SUCCESS);
}
