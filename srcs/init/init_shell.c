/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:42:01 by loamar            #+#    #+#             */
/*   Updated: 2021/04/10 11:35:35 by loamar           ###   ########.fr       */
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

void				prompt(void)
{
	ft_putstr_fd("\e[0;36m", 2);
	ft_putstr_fd("minishell$ ", 2);
	ft_putstr_fd("\e[0;37m", 2);
}
