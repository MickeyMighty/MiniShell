/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:41:31 by tidminta          #+#    #+#             */
/*   Updated: 2021/04/07 12:11:58 by lorenzoamar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int			my_env(t_msh *msh)
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
			ft_putendl_fd(env->second_content, 1);
		}
		env = env->next;
	}
	return (SUCCESS);
}
