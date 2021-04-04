/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:04:14 by loamar            #+#    #+#             */
/*   Updated: 2021/04/04 12:43:43 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

static char		*export_env(t_msh *msh, char *str, int prt)
{
	int		pos;

	pos = 0;
	if (!str)
		return (NULL);
	if (prt == 0)
	{
		while (str[pos] != '=' && str[pos] != '\0')
			pos++;
		return (check_export_env(msh, ft_substr(str, 0, pos)));
	}
	else
	{
		while (str[pos] != '=' && str[pos] != '\0')
			pos++;
		if (str[pos] == '\0')
			return (NULL);
		if (str[pos] == '=')
			pos++;
		return (check_export_env(msh, ft_substr(str, pos, (ft_strlen(str) - pos))));
	}
}

int				check_first_content(char *content, char *str)
{
	int		pos;

	pos = 0;
	if (!content || !str)
		return (ERROR);
	while (str[pos] != '=' && str[pos] != '\0')
		pos++;
	if ((str[pos] != '\0') && (ft_strncmp(str, content, pos) == 0)
	&& (pos == ft_strlen(content)))
		return (SUCCESS);
	else
		return (ERROR);
}

static int		add_back(t_msh *msh, t_env_list *element, char *str)
{
	if (!element->next)
	{
		ft_fill_end_env(msh->env_lair, sep_env(str, 0), sep_env(str, 1));
		return (1);
	}
	return (0);
}

static void		push_to_env(t_msh *msh, char *str)
{
	t_env_list		*element;

	element = msh->env_lair->start;
	if (!element)
	{
		ft_fill_empty_env(msh->env_lair, sep_env(str, 0), sep_env(str, 1));
		return ;
	}
	while (element)
	{
		if (check_first_content(element->first_content, str) == SUCCESS)
		{
			if (element->second_content)
				free(element->second_content);
			element->second_content = ft_strdup(sep_env(str, 1));
			return ;
		}
		else if (add_back(msh, element, str) == 1)
			return ;
		else if (element->next)
			element = element->next;
	}
}

int				my_export(t_msh *msh, t_list *element)
{
	int		pos;

	pos = 1;
	if (!element)
		return (SUCCESS);
	if (ft_strcmp(element->content, "export") == 0
	&& element->tab_args[1] == NULL)
		print_env(msh, element);
	else if (ft_strcmp(element->content, "export") == 0
	&& element->tab_args[1] != NULL)
	{
		while (element->tab_args[pos])
		{
			if (check_arg(msh, element->tab_args[pos]) == ERROR)
				return (ERROR);
			push_to_env(msh, element->tab_args[pos]);
			pos++;
		}
	}
	return (SUCCESS);
}
