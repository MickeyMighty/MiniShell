/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:30:11 by loamar            #+#    #+#             */
/*   Updated: 2021/01/12 16:28:02 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

// ////////////////////////////////////////////////////////////////
// // FONCTIONS POUR CHECK CE QU IL Y A DANS LA LISTE CHAINEE
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
// 		printf("%d-> %s\n", test, current->content);
// 		current = current->next;
// 		test++; // pour le printf
// 	}
// 	printf("| FIN |\n");
// 	printf("size env_lair -> %d\n", env_lair->size);
// 	printf("first env_lair -> %s\n", env_lair->start->content);
// 	printf("end  env_lair -> %s\n", env_lair->end->content);
// }
// ////////////////////////////////////////////////////////////////

static int 	linked_list_env(t_msh *msh, char **env)
{
	int 	count;

	count = 0;
	msh->env_list = NULL;
	msh->env_lair = init_env_lair(msh->env_lair);
	if (msh->env_lair == NULL)
		return (ERROR);
	ft_fill_empty_env(msh->env_lair, env[count]);
	while (env[count])
	{
		count++;
		ft_fill_end_env(msh->env_lair, env[count]);
	}
	// print_list(msh->env_lair);
	return (SUCCESS);
}

static int		get_path(t_msh *msh)
{
	t_env_list 	*element;
	char 		*tmp;

	tmp = NULL;
	element = msh->env_lair->start;
	while (element != NULL)
	{
		if (element->content[0] == 'P'
		&& element->content[1] == 'A'
		&& element->content[2] == 'T'
		&& element->content[3] == 'H'
		&& element->content[4] == '=')
		{
			tmp = ft_substr(element->content, 5,
			ft_strlen(element->content) - 5);
			msh->utils->path = ft_split(tmp, ':');
			return (SUCCESS);
		}
		else
			element = element->next;
	}
	free(tmp);
	return (ERROR);
}

int 	handler_env(t_msh *msh, char **env)
{
	int 	ret;

	ret = 0;
	ret = linked_list_env(msh, env);
	if (ret == ERROR)
		return (ERROR);
	get_path(msh);
	return (SUCCESS);
}
