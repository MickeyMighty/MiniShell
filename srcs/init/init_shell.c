/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:42:01 by loamar            #+#    #+#             */
/*   Updated: 2020/12/08 18:34:41 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static t_msh 	*init_msh(t_msh *msh)
{
	if (!(msh = (t_msh*)malloc(sizeof(t_msh))))
		return (NULL);
	msh->data = NULL;
	msh->list = NULL;
	msh->lair_list = NULL;
	// if (!(data = (t_data*)malloc(sizeof(t_data))))
	// 	return (NULL);
	// data = NULL;
	return (msh);
}

static void 	aff_welcome(void)
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
	ft_putstr("*+*                *+* \n\n");
}

t_msh 	*init_shell(t_msh *msh)
{
	aff_welcome();
	return (init_msh(msh));
}
// t_data		*init_data_struct(t_data *data)
// {
// 	data->count_data = 0;
// }
