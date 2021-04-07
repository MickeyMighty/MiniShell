/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quoteanddollar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzoa <lorenzoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:02:00 by lorenzoa          #+#    #+#             */
/*   Updated: 2021/04/07 13:14:50 by lorenzoamar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

int		data_check_qte(t_msh *msh, int count, int pos, int flag)
{
	if (flag == 0)
	{
		while (msh->data->prompt_data[count][pos] != '\'')
		{
			if (msh->data->prompt_data[count][pos] == '\0')
				return (-1);
			pos++;
		}
	}
	else if (flag == 1)
	{
		pos++;
		while (msh->data->prompt_data[count][pos] != '\"')
		{
			if (msh->data->prompt_data[count][pos] == '\0')
				return (-1);
			pos++;
		}
	}
	return (pos);
}

char	*check_dollar_case(t_msh *msh, char *str)
{
	if (str[msh->utils->pos + 1] == '?')
	{
		msh->utils->pos++;
		return (ft_itoa(g_status));
	}
	if (str[msh->utils->pos + 1] == '$')
	{
		msh->utils->pos++;
		return (ft_itoa(4714));
	}
	return (NULL);
}

int		check_backslash(t_msh *msh, char *str)
{
	if (str[msh->utils->pos] == '\\')
	{
		if (str[msh->utils->pos + 1] == '\0')
			return (-1);
		msh->utils->pos++;
	}
	return (1);
}
