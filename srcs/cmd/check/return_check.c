/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:13:10 by loamar            #+#    #+#             */
/*   Updated: 2021/03/29 16:18:31 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

static	char	*return_less_qte(t_msh *msh, t_env_list *element, int key)
{
	int		pos;

	pos = 1;
	while (element->second_content[msh->utils->len] != '\"'
			&& element->second_content[msh->utils->len] != '\0')
		msh->utils->len++;
	if (element->second_content[msh->utils->len] == '\0')
		return (NULL);
	if (element->second_content[msh->utils->len] == '\"')
		msh->utils->len--;
	if (key == NOQTE)
	{
		if ((msh->utils->no_space == 1) || (msh->utils->no_space == 3))
		{
			while (element->second_content[pos] == ' ')
				pos++;
		}
		else if ((msh->utils->no_space = 2) || (msh->utils->no_space == 3))
		{
			while (element->second_content[msh->utils->len] == ' ')
				msh->utils->len--;
		}
	}
	return (check_content(msh, ft_substr(element->second_content, pos,
					msh->utils->len)));
}

char			*return_element(t_msh *msh, char *tmp, int key)
{
	t_env_list	*element;
	int			start;

	start = 0;
	element = msh->env_lair->start;
	msh->utils->len = 0;
	while (element)
	{
		if (ft_strcmp(tmp, element->first_content) == 0)
		{
			free(tmp);
			if (element->second_content[0] == '\"')
				return (check_content(msh, return_less_qte(msh, element, key)));
			return (check_content(msh, element->second_content));
		}
		element = element->next;
	}
	if (tmp)
		free(tmp);
	return (NULL);
}

char			*return_dollar(t_msh *msh, char *str, int key)
{
	char		*tmp;
	int			len;

	if (str[msh->utils->pos + 1] == '?')
		return (ft_itoa(global_status));
	if ((key == NOQTE && msh->utils->no_space == 0)
			&& check_no_space(msh, str) == 1)
		msh->utils->no_space = 0;
	len = msh->utils->pos;
	len++;
	while (ft_isalnum(str[len]) != 0)
		len++;
	if (len == msh->utils->pos)
		return (ft_strdup("\0"));
	msh->utils->len = len;
	if (key == NOQTE && check_end(str, msh->utils->len) == 1)
	{
		if (msh->utils->no_space == 1)
			msh->utils->no_space = 3;
		else
			msh->utils->no_space = 2;
	}
	tmp = ft_substr(str, msh->utils->pos, len);
	if (key == NOQTE)
		msh->utils->pos = msh->utils->len;
	else
		msh->utils->pos = msh->utils->len - 1;
	if ((tmp = return_element(msh, tmp, key)) != NULL)
		return (tmp);
	return (ft_strdup("\0"));
}

char			*return_quote(t_msh *msh, char *str)
{
	char	*first_step;
	char	*second_step;

	msh->utils->pos++;
	first_step = NULL;
	while (str[msh->utils->pos] && str[msh->utils->pos] != msh->utils->quote)
	{
		second_step = fill_second_step_quote(msh, str, second_step);
		if ((str[msh->utils->pos] != msh->utils->quote)
		&& str[msh->utils->pos + 1] && second_step == NULL)
			second_step = ft_substr(str, msh->utils->pos, 1);
		first_step = ft_strjoin(first_step, second_step);
		if (second_step)
			free(second_step);
		if (str[msh->utils->pos])
			msh->utils->pos++;
	}

	return (first_step);
}

char			*return_all_content(t_msh *msh, char *str)
{
	char	*first_step;
	char	*second_step;

	msh->utils->pos = -1;
	first_step = NULL;
	while (str[++msh->utils->pos])
	{
		second_step = fill_second_step_content(msh, str, second_step);
		if (second_step == NULL)
		{
			if (str[msh->utils->pos] == '\\')
			{
				if (str[msh->utils->pos + 1] == '\0')
					return (NULL);
				msh->utils->pos++;
			}
			second_step = ft_substr(str, msh->utils->pos, 1);
		}
		msh->utils->no_space = 1;
		first_step = ft_strjoin(first_step, second_step);
		if (second_step)
			free(second_step);
	}
	free(str);
	return (first_step);
}
