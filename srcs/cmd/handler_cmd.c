/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 04:46:01 by loamar            #+#    #+#             */
/*   Updated: 2021/01/11 21:05:26 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"


int 	handler_cmd(t_msh *msh, char **env)
{
	int ret;
	t_list 	*element;

	element = msh->lair_list->start;
	while (element->next != NULL)
	{
		if (ft_handler_built_in(msh, element, env) != SUCCESS)
			exec_cmd(msh, element, env);
		element = element->next;
	}
	exit(0);
}
