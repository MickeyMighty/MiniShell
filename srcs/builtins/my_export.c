/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:04:14 by loamar            #+#    #+#             */
/*   Updated: 2021/03/03 14:46:13 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static void push_to_env(t_msh *msh, char *str)
{
    int             pos;
    t_env_list      *element;
    t_env_list      *tmp;

    element = msh->env_list->start;
    if (!element)
    {
        ft_fill_empty_env(msh->env_lair, sep_env(env[count], 0),
        sep_env(env[count], 1));
        return ;
    }
    while (element)
    {
        pos = 0;
        while (element->content[pos] != '=' && en[pos] != '\0')
			pos++;
        if (str[pos] == '\0')
            ft_fill_end_list()
        else if (!element->next)
        {
            ft_fill_end_env(msh->env_lair, sep_env(str[count], 0),
            sep_env(str[count], 1));
            return ;
        }
        else if (element->next)
            element = element->next;
    }
}

int			ft_my_export(t_msh *msh, t_list *element)
{
    char    *tmp;
    int     pos;

    pos = 0;
	if (!element)
		return (ERROR);
    if (ft_strncmp(element->content, "export", 6) == 0
    && element->tab_args == NULL)
        ft_my_env(msh, element);
    else if (ft_strcmp(element->content, "export") == 0
    && element->tab_args != NULL)
    {
        while (element->tab_args[pos] != NULL)
        {
            if (ft_strchr(element->tab_args[pos], '=') != NULL)
                push_to_env(msh, element->tab_args[pos]);
            else
                push_to_env_spe(msh, element->tab_args[pos])
            pos++;
        }
    }
    free(tmp);
	return (SUCCESS);
}
