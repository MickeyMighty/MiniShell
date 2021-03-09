/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 09:12:18 by loamar            #+#    #+#             */
/*   Updated: 2021/03/04 09:55:46 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int     ft_my_exit(t_msh *msh, t_list *element)
{
    free_all(msh);
    exit(EXIT_SUCCESS);
}