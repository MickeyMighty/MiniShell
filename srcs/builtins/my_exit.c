/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 09:12:18 by loamar            #+#    #+#             */
/*   Updated: 2021/03/22 09:53:24 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int     my_exit(t_msh *msh, t_list *element)
{
	if (element->tab_args[1] != NULL)
		return_error(msh, element->content, "numeric argument required");
    free_all(msh, TRUE);
    exit(EXIT_SUCCESS);
}
