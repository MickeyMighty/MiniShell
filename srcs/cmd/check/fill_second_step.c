/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_second_step.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:55:15 by loamar            #+#    #+#             */
/*   Updated: 2021/04/09 13:38:54 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

char	*get_tmp_value(t_msh *msh, char *str, int len)
{
	int			lair;
	int			after_len;
	char		*tmp;

	after_len = 0;
	if (str[len + 1] != '\0')
		after_len = 1;
	lair = len;
	len = (len - (msh->utils->pos - 1));
	tmp = ft_substr(str, msh->utils->pos, len);
	if (after_len == 1)
		msh->utils->pos = len + 1;
	else
		msh->utils->pos = len;
	tmp = return_element(msh, tmp, msh->utils->key);
	if (msh->utils->key == YESQTE && after_len == 1)
		msh->utils->pos++;
	msh->utils->pos = lair;
	return (tmp);
}

char	*fill_step_qte(t_msh *msh, char *str, char *second_step)
{
	if (msh->utils->quote == DQUOTE && str[msh->utils->pos] == '\\'
			&& (str[msh->utils->pos + 1] == DQUOTE
				|| str[msh->utils->pos + 1] == '\\'
				|| str[msh->utils->pos + 1] == '$'))
	{
		msh->utils->backslash_dollar = 1;
		msh->utils->pos++;
	}
	second_step = fill_second_step_quote(msh, str, second_step);
	if (second_step == NULL
			&& ((str[msh->utils->pos] != msh->utils->quote)
				|| ((str[msh->utils->pos] == msh->utils->quote)
					&& (str[msh->utils->pos - 1] == '\\'))))
		second_step = ft_substr(str, msh->utils->pos, 1);
	return (second_step);
}

char	*join_and_free_first_step(t_msh *msh, char *first, char *second,
		int loop)
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
	}
	return (first);
}

char	*fill_second_step_quote(t_msh *msh, char *str, char *second_step)
{
	if ((str[msh->utils->pos] == '$') && msh->utils->quote != SQUOTE
			&& str[msh->utils->pos + 1] && msh->utils->backslash_dollar == 0)
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
				&& (str[msh->utils->pos + 2] == '\0'
					|| str[msh->utils->pos + 2] == DQUOTE
					|| str[msh->utils->pos + 2] == SQUOTE))
		{
			msh->utils->pos++;
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
