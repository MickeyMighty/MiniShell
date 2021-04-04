/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:13:10 by loamar            #+#    #+#             */
/*   Updated: 2021/04/04 10:56:18 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

static char			*return_element(t_msh *msh, char *tmp, int key, int len)
{
	t_env_list	*element;
	int			start;

	start = 0;
	element = msh->env_lair->start;
	while (element)
	{
		if (ft_strncmp(tmp, element->first_content, len) == 0)
			return (check_content(msh, element->second_content, key));
		element = element->next;
	}
	if (tmp)
		free(tmp);
	return (NULL);
}

static	char	*return_tmp_dollar(t_msh *msh, char *str, int len)
{
	char		*tmp;
	int 		after_len;
	int			lair;

	after_len = 0;
	tmp = NULL;
	if (msh->utils->key == NOQTE && (check_end(str, msh->utils->pos) == 1))
	{
		if (msh->utils->no_space == 1)
			msh->utils->no_space = 3;
		else
			msh->utils->no_space = 2;
	}
	if (str[len + 1] != '\0')
		after_len = 1;
	lair = len;
	len = (len - (msh->utils->pos - 1));
	tmp = ft_substr(str, msh->utils->pos, len);
	if (after_len == 1)
		msh->utils->pos = len + 1;
	else
		msh->utils->pos = len;
	tmp = return_element(msh, tmp, msh->utils->key, len);
	if (msh->utils->key == YESQTE && after_len == 1)
		msh->utils->pos++;
	msh->utils->pos = lair;
	if (tmp != NULL)
		return (tmp);
	if (msh->utils->key == NOQTE && str[msh->utils->pos + 1] == '\0')
	{
		msh->utils->tab_specase = add_empty_dollar(msh, NULL, msh->utils->pos_args);
		if (msh->utils->tab_specase == NULL)
			global_error = ERROR;
	}
	return (ft_strdup("\0"));
}

char			*return_dollar(t_msh *msh, char *str, int key)
{
	int			len;

	len = 0;
	msh->utils->key = key;
	if (str[msh->utils->pos + 1] == '?')
	{
		msh->utils->pos++;
		return (ft_itoa(global_status));
	}
	if (str[msh->utils->pos + 1] == '$')
	{
		msh->utils->pos++;
		return (ft_itoa(4714));
	}
	if ((key == NOQTE && msh->utils->no_space == 0)
	&& check_no_space(msh, str) == 1)
		msh->utils->no_space = 0;
	if (str[msh->utils->pos + 1] == '\0')
		return (NULL);
	msh->utils->pos++;
	len = msh->utils->pos;
	while (ft_isalnum(str[len]) != 0)
		len++;
	len--;
	return (return_tmp_dollar(msh, str, len));
}

char			*return_quote(t_msh *msh, char *str)
{
	char	*first_step;
	char	*second_step;

	msh->utils->pos++;
	first_step = NULL;
	msh->utils->loop2 = 0;
	while (str[msh->utils->pos])
	{
		if (str[msh->utils->pos] == msh->utils->quote)
				msh->utils->pos++;
		while (str[msh->utils->pos] && str[msh->utils->pos] != msh->utils->quote)
		{
			if (msh->utils->quote == DQUOTE && str[msh->utils->pos] == '\\'
			&& (str[msh->utils->pos + 1] == DQUOTE || str[msh->utils->pos + 1] == '\\'))
				msh->utils->pos++;
			second_step = fill_second_step_quote(msh, str, second_step);
			if (second_step == NULL
			&& ((str[msh->utils->pos] != msh->utils->quote)
		 	|| ((str[msh->utils->pos] == msh->utils->quote)
			&& (str[msh->utils->pos - 1] == '\\'))))
				second_step = ft_substr(str, msh->utils->pos, 1);
			first_step = join_and_free_first_step(msh, first_step, second_step, 2);
			if (str[msh->utils->pos])
				msh->utils->pos++;
		}
	}
	return (first_step);
}

char			*return_all_content(t_msh *msh, char *str)
{
	char	*first_step;
	char	*second_step;
	char	*tmp;

	msh->utils->pos = 0;
	first_step = NULL;
	msh->utils->loop = 0;
	while (str[msh->utils->pos])
	{
		second_step = NULL;
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
		first_step = join_and_free_first_step(msh, first_step, second_step, 1);
		if (str[msh->utils->pos])
				msh->utils->pos++;
	}
	free(str);
	return (first_step);
}
