/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:42:01 by loamar            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/12/11 03:39:23 by loamar           ###   ########.fr       */
=======
/*   Updated: 2020/12/11 03:17:54 by tidminta         ###   ########.fr       */
>>>>>>> 1577a933a739790afc0ff6c3cfe0c5abc9e3cbbd
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

char			**fill_separator_tab(void)
{
	char **tab;

	tab = (char**)malloc(sizeof(char*) * 8);
	ft_memset(tab, 0, 8);
	tab[0] = "|";
	tab[1] = ";";
	tab[2] = "<";
	tab[3] = ">";
	tab[4] = ">>";
	tab[5] = "&&";
	tab[6] = "||";
	tab[7] = 0;
	return (tab);
}

static t_msh 	*init_msh(t_msh *msh)
{
	if (!(msh = (t_msh*)malloc(sizeof(t_msh))))
		return (NULL);
	msh->data = NULL;
	msh->list = NULL;
	msh->lair_list = NULL;
	msh->utils = NULL;
	if (!(msh->utils = (t_utils*)malloc(sizeof(t_utils))))
		return (NULL);
	msh->utils->check_opt = 0;
	msh->utils->check_arg = 0;
<<<<<<< HEAD
	msh->utils->error_multi_line = 0;
=======
	msh->utils->separator_tab = fill_separator_tab();
>>>>>>> 1577a933a739790afc0ff6c3cfe0c5abc9e3cbbd
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
