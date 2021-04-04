/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 22:39:18 by loamar            #+#    #+#             */
/*   Updated: 2021/04/04 12:49:23 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

void		print_second_env(char *str)
{
	int		pos;

	pos = 0;
	while (str[pos])
	{
		ft_putchar_fd(str[pos], 1);
		if (str[pos] == '\\' && str[pos + 1] == '\\')
			pos++;
		pos++;
	}
}

char	*check_export_env(t_msh *msh, char *str)
{
	char	*first_step;
	char	*second_step;
	char	*tmp;
	int		pos;

	pos = 0;
	msh->utils->loop = 0;
	msh->utils->loop2 = 0;
	msh->utils->loop3 = 0;
	first_step = NULL;
	while (str[pos])
	{
		second_step = NULL;
		if (str[pos] == '\\' && str[pos] == '\\')
			pos++;
		second_step = ft_substr(str, pos, 1);
		first_step = join_and_free_first_step(msh, first_step, second_step, 1);
		msh->utils->loop = 1;
		if (str[pos])
			pos++;
	}
	free(str);
	return (first_step);
}

void	print_env(t_msh *msh, t_list *element)
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
			if (env->first_content && env->first_content[0] == limit)
			{
				ft_putstr_fd("declare -x ", 1);
				ft_putstr_fd(env->first_content, 1);
				if (env->second_content)
				{
					ft_putstr_fd("=", 1);
					ft_putstr_fd("\"", 1);
					print_second_env(env->second_content);
					// ft_putstr_fd(env->second_content, 1);
					ft_putendl_fd("\"", 1);
				}
				else
					ft_putstr_fd("\n", 1);
			}
			env = env->next;
		}
		limit++;
	}
}

int		check_arg(t_msh *msh, char *str)
{
	int		pos;
	int		check;

	pos = 0;
	check = 0;
	while (str[pos])
	{
		printf("str[%c]\n", str[pos]);
		if (str[pos] == '=')
			return (SUCCESS);
		if (str[pos] == '_' && pos == 0)
			return (ERROR);
		if ((ft_isalnum(str[pos]) == 1 && check == 0))
		{
			return (return_error(ERROR_QTE, "export", str,
			": not a valid identifier"));
		}
		if (check = 0 && ((ft_isalpha(str[pos]) != 1)
		|| (ft_isalnum(str[pos]) != 1) || (str[pos] != '_')))
		{
			return (return_error(ERROR_QTE, "export", str,
			": not a valid identifier"));
		}
		if (ft_isalpha(str[pos]) == 1)
			check = 1;
		if (str[pos])
			pos++;
	}
	return (SUCCESS);
}
// printf("str[%c]\n", str[pos]);
// if (str[pos] == '=')
// return (SUCCESS);
// if (str[pos] == '_' && pos == 0)
// return (ERROR);
// if ((ft_isalnum(str[pos]) == 1 && check == 0) || ((str[pos] != '\\')
// && (str[pos] != '/') && (str[pos] != ' ')))
// {
// 	printf("ici 1\n");
// 	return (return_error(ERROR_QTE, "export", str,
// 	": not a valid identifier"));
// }
// if ((ft_isalpha(str[pos]) == 0) && (ft_isalnum(str[pos]) == 0)
// && (str[pos] != '_') && (str[pos] != '\\') && (str[pos] != '/')
// && (str[pos] != ' '))
// {
// 	printf("ici 2\n");
// 	return (return_error(ERROR_QTE, "export", str,
// 	": not a valid identifier"));
// }
// if (ft_isalpha(str[pos]) == 1)
// check = 1;
// if (str[pos])
// pos++;
