/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 04:42:10 by loamar            #+#    #+#             */
/*   Updated: 2020/12/11 07:39:21 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int 	linked_list_data(t_msh *msh)
{
	int 	count;

	count = 0;
	msh->list = NULL;
	msh->lair_list = init_lair_list(msh->lair_list);
	ft_fill_empty_list(msh->lair_list, msh->data->prompt_data[count]);
	while (count < msh->data->size_data)
	{
		count++;
		ft_fill_end_list(msh->lair_list, msh->data->prompt_data[count]);
	}
	// printf("\nLIST CHAINEE\n");
	// print_list(msh->lair_list);
	return (1);
}

/*
** commandes?
** echo -n
** pwd
** export
** unset
** env
** exit
*/


static int				separator_check(t_msh *msh, char *s)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = msh->utils->sep_tab;
	while (tmp[i])
	{
		if (!ft_strncmp(s, tmp[i], ft_strlen(s))
			&& ft_strlen(s) == ft_strlen(tmp[i]))
			return (1);
		i++;
	}
	return (0);
}

/*
** token recognition a finir, bon pour cmd separator et args
** d'autres tests sont a prevoirs, relancer l'op qd on est sur un sep
** implementer/finir option_check(s);
** lors des test
*/

static int		token_recognition(t_msh *msh, char *s, int indice)
{
	if (indice == 0)
		return (CMD);
	// else if (indice =! 0 && option_check(s))
	// 	return (OPTION);
	else if (indice != 0 && separator_check(msh, s))
		return (SEPARATOR);
	else
	{
		msh->utils->check_arg = 1;
		return (ARGS);
	}
	return (0);
}

static int		set_token(t_msh *msh)
{
	t_list	*lst;
	int		i;

	lst = msh->lair_list->start;
	i = 0;
	while (lst->content)
	{
		printf("avant token[%s] = %i\n", lst->content, lst->token);
		lst->token = token_recognition(msh, lst->content, i);
		printf("apres token[%s] = %i\n", lst->content, lst->token);
		lst = lst->next;
		i++;
	}
	return (0);
}

int 	handler_list(t_msh *msh)
{
	// printf("debut de chaine -> %s\n", data->prompt_data[0]);
	linked_list_data(msh);
	// set_token(msh);
	free_data(msh);
	return (1);
}
