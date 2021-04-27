/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:42:01 by loamar            #+#    #+#             */
/*   Updated: 2021/04/27 02:45:02 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

void	aff_welcome(void)
{
	ft_putstr("\n");
	ft_putstr("   +--------------+\n");
	ft_putstr("   |.------------.|\n");
	ft_putstr("   ||            ||\n");
	ft_putstr("   || WELCOME TO ||\n");
	ft_putstr("   ||  MINISHELL ||\n");
	ft_putstr("   ||            ||\n");
	ft_putstr("   |+------------+|\n");
	ft_putstr("   +-..--------..-+\n");
	ft_putstr("   .--------------.\n");
	ft_putstr("  | .============. | \n");
	ft_putstr(" | .==============. | \n");
	ft_putstr("| ___________________| \n");
	ft_putstr("|____________________| \n");
	ft_putstr("*+*  BY   LOAMAR   *+* \n\n");
}

void	prompt(void)
{
	ft_putstr_fd("\e[0;36m", 2);
	ft_putstr_fd("minishell$ ", 2);
	ft_putstr_fd("\e[0;37m", 2);
}

t_utils			*init_utils(t_utils *utils)
{
	utils->check = 0;
	utils->size_tab = 0;
	utils->pos_args = 1;
	utils->export_check = 0;
	return (utils);
}
