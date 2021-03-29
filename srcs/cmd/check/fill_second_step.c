/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_second_step.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:55:15 by loamar            #+#    #+#             */
/*   Updated: 2021/03/28 21:54:12 by loamar           ###   ########.fr       */
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

char	*fill_second_step_quote(t_msh *msh, char *str, char *second_step)
{
	if (msh->utils->quote == DQUOTE && str[msh->utils->pos] == '\\'
	&& (str[msh->utils->pos + 1] == '$'
	|| str[msh->utils->pos + 1] == DQUOTE
	|| str[msh->utils->pos + 1] == '\\'))
		msh->utils->pos++;
	else if (str[msh->utils->pos] == '$' && msh->utils->quote == DQUOTE
	&& (str[msh->utils->pos + 1] != msh->utils->quote
	|| str[msh->utils->pos + 1] != '\\'))
		second_step = return_dollar(msh, str, YESQTE);
	else
		return (NULL);
	return (second_step);
}

char	*fill_second_step_content(t_msh *msh, char *str, char *second_step)
{
	if (str[msh->utils->pos] == DQUOTE || str[msh->utils->pos] == SQUOTE)
	{
		msh->utils->quote = str[msh->utils->pos];
		second_step = return_quote(msh, str);
	}
	else if ((str[msh->utils->pos] == '$') && ((str[msh->utils->pos + 1] != ' ')
	&& (str[msh->utils->pos + 1] != '\0')))
		second_step = return_dollar(msh, str, NOQTE);
	else
		return (NULL);
	return (second_step);
}
