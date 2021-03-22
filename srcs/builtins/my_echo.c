/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 06:06:53 by loamar            #+#    #+#             */
/*   Updated: 2021/03/22 12:01:16 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

// int 	my_echo(t_msh *msh, t_list *element)
// {
// 	int 	pos;
// 	int 	option_n;
//
// 	option_n = 0;
// 	pos = 1;
// 	if (element->tab_args[pos] == NULL)
// 		return ;
// 	else
// 	{
// 		if (ft_strcmp("-n", element->tab_args[pos]) == 0)
// 		{
// 			option_n = 1;
// 			pos++;
// 		}
// 		while (element->tab_args[pos] != NULL)
// 		{
// 			ft_putstr_fd(element->tab_args[pos], 1);
// 			if (element->tab_args[pos + 1] != NULL)
// 				ft_putstr_fd(" ", 1);
// 			pos++;
// 		}
// 		if (option_n = 0)
// 			ft_putstr_fd("\n", 1);
// 	}
// 	return (SUCCESS);
// }
