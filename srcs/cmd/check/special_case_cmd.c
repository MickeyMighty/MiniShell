/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:25:23 by loamar            #+#    #+#             */
/*   Updated: 2021/04/02 21:24:53 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

static int		*realloc_int_tab(int *tab, int size)
{
	int	*fresh;
	int pos;

	pos = 0;
	if (size == 1 && tab == NULL)
	{
		if (!(fresh = (int *)malloc(sizeof(int) * (1))))
			return (NULL);
	}
	else
	{
		if (!(fresh = (int *)malloc(sizeof(int) * (size))))
			return (NULL);
		while (pos < (size - 1))
		{
			fresh[pos] = tab[pos];
			pos++;
		}
		free(tab);
	}
	return (fresh);
}

int 	*add_empty_dollar(t_msh *msh, t_list *element, int add)
{
	int 	*tmp;

	if (msh->utils->size_tab == 0)
	{
		msh->utils->tab_specase = realloc_int_tab(msh->utils->tab_specase, 1);
		if (msh->utils->tab_specase == NULL)
			return (NULL);
		msh->utils->tab_specase[0] = add;
		msh->utils->size_tab = 1;
	}
	else
	{
		msh->utils->tab_specase = realloc_int_tab(msh->utils->tab_specase,
		msh->utils->size_tab + 1);
		if (msh->utils->tab_specase == NULL)
			return (NULL);
		msh->utils->tab_specase[msh->utils->size_tab] = add;
		msh->utils->size_tab++;
	}
	return (msh->utils->tab_specase);
}

int 	check_specase(t_msh *msh, int pos)
{
	int		limite;

	limite = 0;
	if (msh->utils->tab_specase == NULL)
		return (0);
	while (limite <= (msh->utils->size_tab - 1))
	{
		if (msh->utils->tab_specase[limite] == pos)
			return (1);
		limite++;
	}
	return (0);
}
