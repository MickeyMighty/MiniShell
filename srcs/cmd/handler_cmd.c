/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:33 by loamar            #+#    #+#             */
/*   Updated: 2021/01/12 16:04:55 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	handler_cmd(t_msh *msh, char **env)
{
	int ret;
	t_list 	*element;

	element = msh->lair_list->start;
	while (element != NULL)
	{
		if (element->token == CMD)
		{
			exec_cmd(msh, element, env);
			element = element->next;
			while (element->token == OPTION || element->token == ARGS)
				element = element->next;
		}
		else
			element = element->next;
	}
	// while (element->next != NULL)
	// {
	// 	if (ft_handler_built_in(msh, element, env) != SUCCESS)
	// 		exec_cmd(msh, element, env);
	// 	element = element->next;
	// }
	exit(0);
}
