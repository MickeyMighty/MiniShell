/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:25:23 by loamar            #+#    #+#             */
/*   Updated: 2021/04/27 17:15:16 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

int				check_end(char *str, int pos)
{
	if (str[pos + 1] != '\0' && (ft_isalnum(str[pos + 1]) == 0))
		return (1);
	else
		return (0);
}

int				return_pos(t_msh *msh, char *str, int pos)
{
	while (str[pos] == ' ' && str[pos + 1] == ' ')
		pos++;
	if (str[pos] == ' ' && str[pos + 1] == '\0')
		pos = put_pos_check(msh, str, pos, 2);
	return (pos);
}

static int		*realloc_int_tab(int *tabs, int size)
{
	int	*fresh;
	int pos;

	pos = 0;
	if (size == 1 && tabs == NULL)
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
			fresh[pos] = tabs[pos];
			pos++;
		}
		free(tabs);
	}
	return (fresh);
}

int				*add_empty_dollar(t_msh *msh, int add)
{
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

int				check_specase(t_msh *msh, int pos)
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
