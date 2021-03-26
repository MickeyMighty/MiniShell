/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:56:45 by loamar            #+#    #+#             */
/*   Updated: 2021/03/26 09:26:14 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static 		int 	pop_env(t_msh *msh, int pos)
{
	t_env_list	*delete_element;
	t_env_list	*now_element;
	int		i;

	i = 1;
  	if(msh->env_lair->size == 0)
    	return (-1);
    now_element = msh->env_lair->start;
	while (i < pos)
	{
		now_element = now_element->next;
		i++;
	}
    delete_element = now_element;
	if (now_element->next != NULL)
		now_element->next->previous = now_element->previous;
	else
		msh->env_lair->end = now_element->previous;
	if (now_element->previous != NULL)
		now_element->previous->next = now_element->next;
    if (delete_element->first_content)
  	    free(delete_element->first_content);
    if (delete_element->second_content)
  	    free(delete_element->second_content);
  	free(delete_element);
  	msh->env_lair->size--;
  	return (0);
}

static int      find_env(t_msh *msh, char *content)
{
    t_env_list  *element;

    if (!content)
        return (-1);
    element = msh->element->env_lair->start;
    if (!element)
        return (-1);
    while (element)
    {
        if (ft_strcmp(content, element->first_content) == 0)
            return (index);
        element = element->next;
        index++;
    }
    return (-1);
}

int 	my_unset(t_msh *msh, t_element *element)
{
	size_t	i;
	ssize_t	index;

	global_status = 0;
	if (!element->tab_args[1])
		return (SUCCESS);
	i = 0;
	while (element->tab_args[++i])
	{
		index = find_env(element->tab_args[i]);
		if (index != -1)
		{
			if (g_envs[index])
			         pop_env(msh, index);
		}
		else
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(element->tab_args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			global_status = 1;
		}
	}
	return (1);
}
