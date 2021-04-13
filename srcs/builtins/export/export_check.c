/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 22:39:18 by loamar            #+#    #+#             */
/*   Updated: 2021/04/13 15:32:29 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

static	char	*fill_first_step(t_msh *msh, char *str, char *first_step,
int pos)
{
	int		dollar_case;
	char	*second_step;

	dollar_case = 0;
	second_step = NULL;
	if (str[pos] == '\\' && str[pos + 1] != '\\')
		second_step = ft_strdup("\\\\");
	else if (str[pos] == '$' && ft_isalpha(str[pos + 1]) == 0)
	{
		dollar_case = 1;
		second_step = ft_strdup("\\");
	}
	else
		second_step = ft_substr(str, pos, 1);
	first_step = ft_free_strjoin(first_step, second_step, 1, 1);
	if (dollar_case == 1)
	{
		second_step = ft_substr(str, pos, 1);
		first_step = ft_free_strjoin(first_step, second_step, 1, 1);
	}
	return (first_step);
}

char			*export_secondcontent(t_msh *msh, char *str, int start)
{
	char	*first_step;
	int		pos;

	first_step = NULL;
	msh->utils->loop2 = 0;
	pos = start;
	while (str[pos])
	{
		first_step = fill_first_step(msh, str, first_step, pos);
		if (str[pos])
			pos++;
	}
	return (first_step);
}

char			*check_export_env(t_msh *msh, char *str)
{
	char	*first_step;
	char	*second_step;
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

static	int		return_error_export(t_msh *msh, char *str, int pos)
{
	if (str[pos] == '_' && pos == 0)
		return (ERROR);
	if ((ft_isdigit(str[pos]) == 1 && msh->utils->check == 0))
	{
		return (return_error(ERROR_QTE, "export", str,
		": not a valid identifier"));
	}
	if (msh->utils->check == 0 && (ft_isalpha(str[pos]) != 1)
	&& ((ft_isdigit(str[pos]) == 1) || (str[pos] != '_')))
	{
		return (return_error(ERROR_QTE, "export", str,
		": not a valid identifier"));
	}
	if (ft_isalpha(str[pos]) == 1)
		msh->utils->check = 1;
	else if (msh->utils->check == 0)
	{
		return (return_error(ERROR_QTE, "export", str,
		": not a valid identifier"));
	}
	return (SUCCESS);
}

int				check_arg(t_msh *msh, char *str)
{
	int		pos;

	pos = 0;
	msh->utils->check = 0;
	if (str[pos] == '=')
	{
		return (return_error(ERROR_QTE, "export", str,
		": not a valid identifier"));
	}
	if (str[pos] == '\0')
	{
		return (return_error(ERROR_QTE, "export", str,
		": not a valid identifier"));
	}
	while (str[pos])
	{
		if (str[pos] == '=')
			return (SUCCESS);
		if (return_error_export(msh, str, pos) == ERROR)
			return (ERROR);
		if (str[pos])
			pos++;
	}
	return (SUCCESS);
}
