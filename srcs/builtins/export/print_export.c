/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzoa <lorenzoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:37:21 by lorenzoa          #+#    #+#             */
/*   Updated: 2021/04/13 17:06:20 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

void			push_to_env(t_msh *msh, char *str)
{
	t_env_list		*element;
	int				check;

	check = 0;
	element = msh->env_lair->start;
	if (!element)
	{
		ft_fill_empty_env(msh->env_lair, sep_env(str, 0, EXPORT),
				sep_env(str, 1, EXPORT));
		return ;
	}
	while (element)
	{
		check = check_first_content(element->first_content, str);
		if (check == SUCCESS)
		{
			if (element->second_content)
				free(element->second_content);
			element->second_content = ft_strdup(sep_env(str, 1, EXPORT));
			return ;
		}
		else if ((check == ERROR) && add_back(msh, element, str) == 1)
			return ;
		else if (check == ERROR_EXPORT)
			return ;
		else if (element->next)
			element = element->next;
	}
}

static	void	print_content(t_env_list *env, int limit)
{
	if (env->first_content && env->first_content[0] == limit)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(env->first_content, 1);
		if (env->second_content)
		{
			ft_putstr_fd("=", 1);
			ft_putstr_fd("\"", 1);
			ft_putstr_fd(env->second_content, 1);
			ft_putendl_fd("\"", 1);
		}
		else
			ft_putstr_fd("\n", 1);
	}
}

void			print_env(t_msh *msh)
{
	t_env_list		*env;
	int				limit;

	limit = 0;
	if (!msh->env_lair->start)
		return ;
	while (limit <= 255)
	{
		env = msh->env_lair->start;
		while (env && env->first_content && env->first_content[0] != limit)
			env = env->next;
		while (env)
		{
			print_content(env, limit);
			env = env->next;
		}
		limit++;
	}
}
