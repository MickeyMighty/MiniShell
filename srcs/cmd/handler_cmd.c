/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 04:46:01 by loamar            #+#    #+#             */
/*   Updated: 2021/01/11 15:22:13 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	handler_cmd(t_msh *msh, char **env)
{
	t_list 	*element;

	element = msh->lair_list->start;
	while (element)
	{
		exec_cmd(msh, element, env);
		element = element->next;
	}
	exit(0);
}
