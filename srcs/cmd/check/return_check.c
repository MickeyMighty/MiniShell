/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:13:10 by loamar            #+#    #+#             */
/*   Updated: 2021/04/13 16:11:44 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

char			*return_element(t_msh *msh, char *tmp, int key)
{
	t_env_list	*element;

	element = NULL;
	element = msh->env_lair->start;
	while (element)
	{
		if (ft_strcmp(tmp, element->first_content) == 0)
			return (check_content(msh, element->second_content, key));
		element = element->next;
	}
	if (tmp)
		free(tmp);
	return (NULL);
}

static	char		*return_tmp_dollar(t_msh *msh, char *str, int len)
{
	char		*tmp;

	tmp = NULL;
	if (msh->utils->key == NOQTE && (check_end(str, msh->utils->pos) == 1))
	{
		if (msh->utils->no_space == 1)
			msh->utils->no_space = 3;
		else
			msh->utils->no_space = 2;
	}
	tmp = get_tmp_value(msh, str, len);
	if (tmp != NULL)
		return (tmp);
	if (msh->utils->key == NOQTE && str[msh->utils->pos + 1] == '\0')
	{
		msh->utils->tab_specase = add_empty_dollar(msh, msh->utils->pos_args);
		if (msh->utils->tab_specase == NULL)
			g_error = ERROR;
	}
	return (ft_strdup("\0"));
}

char				*return_dollar(t_msh *msh, char *str, int key)
{
	int			len;

	len = 0;
	msh->utils->key = key;
	if (str[msh->utils->pos + 1] == '?' || str[msh->utils->pos + 1] == '$')
		return (check_dollar_case(msh, str));
	if ((key == NOQTE && msh->utils->no_space == 0)
	&& check_no_space(msh, str) == 1)
		msh->utils->no_space = 0;
	if (str[msh->utils->pos + 1] == '\0'
	|| ft_isalpha(str[msh->utils->pos + 1]) == 0)
		return (NULL);
	msh->utils->pos++;
	len = msh->utils->pos;
	while (ft_isalnum(str[len]) != 0)
		len++;
	len--;
	return (return_tmp_dollar(msh, str, len));
}

char				*return_quote(t_msh *msh, char *str)
{
	char	*first_step;
	char	*second_step;

	msh->utils->pos++;
	first_step = NULL;
	second_step = NULL;
	msh->utils->loop2 = 0;
	while (str[msh->utils->pos])
	{
		msh->utils->backslash_dollar = 0;
		if (str[msh->utils->pos] == msh->utils->quote)
			msh->utils->pos++;
		while (str[msh->utils->pos] && str[msh->utils->pos] !=
		msh->utils->quote)
		{
			second_step = fill_step_qte(msh, str, second_step);
			if (str[msh->utils->pos])
				msh->utils->pos++;
		}
	}
	return (first_step);
}

char				*return_all_content(t_msh *msh, char *str)
{
	char	*first_step;
	char	*second_step;

	first_step = NULL;
	msh->utils->pos = 0;
	msh->utils->loop = 0;
	while (str[msh->utils->pos])
	{
		second_step = NULL;
		second_step = fill_second_step_content(msh, str, second_step);
		if (second_step == NULL && str[msh->utils->pos])
		{
			if (check_backslash(msh, str) == -1)
				return (NULL);
			second_step = ft_substr(str, msh->utils->pos, 1);
		}
		msh->utils->no_space = 1;
		first_step = ft_free_strjoin(first_step, second_step);
		if (str[msh->utils->pos])
			msh->utils->pos++;
	}
	free(str);
	return (first_step);
}
