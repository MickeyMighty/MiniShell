/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:30:11 by loamar            #+#    #+#             */
/*   Updated: 2021/03/22 17:45:04 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

// ////////////////////////////////////////////////////////////////
// // FONCTIONS POUR CHECK CE QU IL Y A DANS LA LISTE CHAINEE
static void 	print_list(t_env_lair *env_lair)
{
	int 	test; // pour le printf

	test = 1; // pour le printf
	t_env_list *current;

	current = env_lair->start;
	printf("| DEBUT | \n");
	while (current)
	{
		printf("%d-> %s\n", test, current->first_content);
		printf("%d-> %s\n", test, current->second_content);
		printf("=========\n");
		current = current->next;
		test++; // pour le printf
	}
	printf("| FIN |\n");
	printf("size env_lair -> %d\n", env_lair->size);
	// printf("first env_lair -> %s\n", env_lair->start->content);
	// printf("end  env_lair -> %s\n", env_lair->end->content);
}
////////////////////////////////////////////////////////////////

char	*sep_env(char *str, int prt)
{
	int 	pos;

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

static int		get_path(t_msh *msh)
{
	t_env_list 	*element;

	printf("| - ");
	element = msh->env_lair->start;
	printf("|| - ");
	while (element != NULL)
	{
		printf("||| - ");
		if ((ft_strlen(element->first_content) >= 4)
		&& element->first_content[0] == 'P'
		&& element->first_content[1] == 'A'
		&& element->first_content[2] == 'T'
		&& element->first_content[3] == 'H')
		{
			printf("|||| - ");
			msh->utils->path = ft_split(element->second_content, ':');
			return (SUCCESS);
		}
		else
			element = element->next;
		printf("||||| - ");
	}
	printf("|||||| - ");
	msh->utils->path = NULL;
	printf("||||||| - ");
	return (ERROR);
}

void 	handler_env(t_msh *msh, char **env)
{
	int 	count;

	count = 0;
	msh->env_lair = init_env_lair(msh->env_lair);
	if (global_error == ERROR)
		return ;
	msh->env_list = NULL;
	ft_fill_empty_env(msh->env_lair, sep_env(env[count], 0),
	sep_env(env[count], 1));
	while (env[++count] != NULL)
	{
		ft_fill_end_env(msh->env_lair, sep_env(env[count], 0),
		sep_env(env[count], 1));
	}
	get_path(msh);
}
