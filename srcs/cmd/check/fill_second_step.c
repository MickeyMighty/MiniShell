/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_second_step.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:55:15 by loamar            #+#    #+#             */
/*   Updated: 2021/04/04 10:55:26 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

char	*join_and_free_first_step(t_msh *msh, char *first, char *second, int loop)
{
	if ((msh->utils->loop == 1 && loop == 1)
	|| (msh->utils->loop2 == 1 && loop == 2)
	|| (msh->utils->loop3 == 1 && loop == 3))
	{
		first = ft_free_strjoin(first, second, 1, 1);
		if (loop == 1)
			msh->utils->loop = 0;
		else if (loop == 2)
			msh->utils->loop2 = 0;
		else if (loop == 3)
			msh->utils->loop3 = 0;
	}
	else
	{
		first = ft_free_strjoin(first, second, 0, 1);
		if (loop == 1)
			msh->utils->loop = 1;
		else if (loop == 2)
			msh->utils->loop2 = 1;
		else if (loop == 3)
			msh->utils->loop3 = 1;
		msh->utils->loop = 1;
	}
	return (first);
}

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
	if ((str[msh->utils->pos] == '$') && msh->utils->quote != SQUOTE
	&& str[msh->utils->pos + 1])
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
		if (str[msh->utils->pos + 1] == msh->utils->quote
		&& str[msh->utils->pos + 2] == '\0')
		{
			msh->utils->pos += 2;
			second_step = ft_strdup("\0");
		}
		else
			second_step = return_quote(msh, str);
	}
	else if (str[msh->utils->pos] == '$')
		second_step = return_dollar(msh, str, NOQTE);
	else
		return (NULL);
	return (second_step);
}
