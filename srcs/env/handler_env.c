/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:30:11 by loamar            #+#    #+#             */
/*   Updated: 2021/03/29 01:15:31 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

void		set_env(t_msh *msh, char *first_content, char *second_content)
{
	t_env_list	*element;

	if (!first_content)
		return ;
	element = msh->env_lair->start;
	if (!element || element == NULL)
		ft_fill_empty_env(msh->env_lair, first_content, second_content);
	else
		ft_fill_end_env(msh->env_lair, first_content, second_content);
}

char		*get_env(t_msh *msh, char *str)
{
	t_env_list	*element;

	element = msh->env_lair->start;
	if (element == NULL || !element)
		return (NULL);
	while (element)
	{
		if (ft_strcmp(str, element->first_content) == 0)
		{
			if (!element->second_content)
				return (NULL);
			else
				return (element->second_content);
		}
		element = element->next;
	}
	return (NULL);
}

char		*sep_env(char *str, int prt)
{
	int		pos;

	pos = 0;
	if (!str)
		return (NULL);
	if (prt == 0)
	{
		while (str[pos] != '=' && str[pos] != '\0')
			pos++;
		return (ft_substr(str, 0, pos));
	}
	else
	{
		while (str[pos] != '=' && str[pos] != '\0')
			pos++;
		if (str[pos] == '\0')
			return (NULL);
		if (str[pos] == '=')
			pos++;
		return (ft_substr(str, pos, (ft_strlen(str) - pos)));
	}
}

int			handler_env(t_msh *msh, char **env)
{
	int		count;

	count = 0;
	msh->env_lair = init_env_lair(msh->env_lair);
	if (msh->env_lair == NULL)
		return (ERROR);
	msh->env_list = NULL;
	ft_fill_empty_env(msh->env_lair, sep_env(env[count], 0),
	sep_env(env[count], 1));
	while (env[++count] != NULL)
	{
		ft_fill_end_env(msh->env_lair, sep_env(env[count], 0),
		sep_env(env[count], 1));
	}
	return (SUCCESS);
}
