/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:04:14 by loamar            #+#    #+#             */
/*   Updated: 2021/03/05 08:58:24 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

// static void 	print_list(t_env_lair *env_lair)
// {
// 	int 	test; // pour le printf
//
// 	test = 1; // pour le printf
// 	t_env_list *current;
//
// 	current = env_lair->start;
// 	printf("| DEBUT | \n");
// 	while (current != NULL)
// 	{
// 		printf("%d-> %s\n", test, current->first_content);
// 		printf("%d-> %s\n", test, current->second_content);
// 		printf("=========\n");
// 		current = current->next;
// 		test++; // pour le printf
// 	}
// 	printf("| FIN |\n");
// 	printf("size env_lair -> %d\n", env_lair->size);
// 	// printf("first env_lair -> %s\n", env_lair->start->content);
// 	// printf("end  env_lair -> %s\n", env_lair->end->content);
// }

static int  check_first_content(char *content, char *str)
{
	int		pos;

	pos = 0;
    if (!content || !str)
        return (ERROR);
	while (str[pos] != '=' && str[pos] != '\0')
		pos++;
    if (str[pos] != '\0' && ft_strncmp(content, str, pos) == 0)
        return (SUCCESS);
    else
        return (ERROR);
}

static void push_to_env(t_msh *msh, char *str)
{
    t_env_list      *element;

    element = msh->env_lair->start;
    if (!element)
    {
        ft_fill_empty_env(msh->env_lair, sep_env(str, 0),
        sep_env(str, 1));
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
        else if (!element->next)
        {
            ft_fill_end_env(msh->env_lair, sep_env(str, 0),
            sep_env(str, 1));
            return ;
        }
        else if (element->next)
            element = element->next;
    }
}

int			ft_my_export(t_msh *msh, t_list *element)
{
    int     pos;

    pos = 1;
	if (!element)
		return (ERROR);

    if (ft_strcmp(element->content, "export") == 0
    && element->tab_args[1] == NULL)
        ft_my_env(msh, element);
    else if (ft_strcmp(element->content, "export") == 0
    && element->tab_args[1] != NULL)
    {
        while (element->tab_args[pos])
        {
            push_to_env(msh, element->tab_args[pos]);
            pos++;
        }
    }
	return (SUCCESS);
}
