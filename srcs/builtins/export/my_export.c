/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:04:14 by loamar            #+#    #+#             */
/*   Updated: 2021/04/16 11:11:05 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

int				check_first_content(char *content, char *str)
{
	size_t		pos;

	pos = 0;
	if (!content || !str)
		return (ERROR);
	while (str[pos] != '=' && str[pos] != '\0')
		pos++;
	if ((str[pos] == '\0') && (ft_strncmp(str, content, pos) == 0)
	&& (pos == ft_strlen(content)))
		return (ERROR_EXPORT);
	else if ((str[pos] != '\0') && (ft_strncmp(str, content, pos) == 0)
	&& (pos == ft_strlen(content)))
		return (SUCCESS);
	else
		return (ERROR);
}

int		add_back(t_msh *msh, t_env_list *element, char *str)
{
	if (!element->next)
	{
		ft_fill_end_env(msh->env_lair, sep_env(str, 0, EXPORT),
		sep_env(str, 1, EXPORT));
		return (1);
	}
	return (0);
}

static	int		handler_check_export(t_msh *msh, t_list *element, int pos,
int error)
{
	while (element->tab_args[pos])
	{
		if (check_arg(msh, element->tab_args[pos]) == ERROR)
		{
			error = 1;
			pos++;
		}
		else
		{
			push_to_env(msh, element->tab_args[pos]);
			pos++;
		}
	}
	if (error == 1)
		return (ERROR);
	return (SUCCESS);
}

int				my_export(t_msh *msh, t_list *element)
{
	int		pos;
	int		error;

	error = 0;
	pos = 1;
	if (!element)
		return (SUCCESS);
	if (ft_strcmp(element->content, "export") == 0
	&& element->tab_args[1] == NULL)
		print_env(msh);
	else if (ft_strcmp(element->content, "export") == 0
	&& element->tab_args[1] != NULL)
	{
		if (handler_check_export(msh, element, pos, error) == ERROR)
			return (ERROR);
	}
	if (msh->utils->pipe == 1)
		free_all(msh, EXIT);
	return (SUCCESS);
}
