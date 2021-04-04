/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:41:31 by tidminta          #+#    #+#             */
/*   Updated: 2021/04/04 02:43:26 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int			my_env(t_msh *msh, t_list *element)
{
	t_env_list		*env;

	if (!msh->env_lair->start)
		return (SUCCESS);
	env = msh->env_lair->start;
	while (env)
	{
		if (env->first_content && env->second_content)
		{
			ft_putstr_fd(env->first_content, 1);
			ft_putstr_fd("=", 1);
			print_second_env(env->second_content);
		}
		env = env->next;
	}
	return (SUCCESS);
}
