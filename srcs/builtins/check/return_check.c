/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:13:10 by loamar            #+#    #+#             */
/*   Updated: 2021/03/20 22:54:35 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static 	char 	*return_less_qte(t_msh *msh, t_list *element, int key)
{
	int		pos;

	pos = 1;
	while (element->second_content[msh->utils->len] != '\"'
	&& element->second_content[msh->utils->len] != '\0')
		msh->utils->len++;
	if (element->second_content[msh->utils->len] == '\0')
		return (NULL);
	if (element->second_content[msh->utils->len] == '\"')
		len--;
	if (key = NOQUOTE)
	{
		if (msh->utils->no_space = 1 || msh->utils->no_space == 3)
		{
			while(element_second[pos] == ' ')
				pos++;
		}
		else if (msh->utils->no_space = 2 || msh->utils->no_space == 3)
		{
			while(element_second[len] == ' ')
				len--;
		}
	}
	return (check_content(msh, ft_substr(element->second_content, pos, len)));
}

static char 	*return_element(t_msh *msh, t_list *element, char *tmp, int key)
{
	int		start;

	start = 0;
	msh->utils->len = 0;
	while (element)
	{
		if (ft_strcmp(tmp, element->first_content) == 0)
		{
			free(tmp);
			if (element->second_content[0] == '\"')
				return (return_content(return_less_qte(msh, element, key)));
			return (ret_cont(element->second_content));
		}
		element = element->next;
	}
	if (tmp)
		free(tmp);
	return (NULL);
}

static char 	*return_dollar(t_msh *msh, char *str, int key)
{
    t_env_list  *element;
	char 		*tmp;
	int 		len;

	msh->utils->pos++;
	if (key == NOQUOTE && msh->utils->no_space == 0
	&& check_no_space(msh, str) == 1);
		msh->utils->no_space == 3;
	while (str[msh->utils->pos] != ' ')
    element = msh->env_lair->start;
	len = msh->utils->pos;
	while (ft_isalnum(str[len]) != 0)
		len++;
	if (len == msh->utils->pos)
		return (ft_strdup("\0"));
	msh->utils += len;
	if (key == NOQUOTE && check_end(str, msh->utils->pos) == 2)
		msh->utils->no_space == 0;
	tmp = ft_substr(str, msh->utils->pos, len);
	if ((tmp = return_element(msh, element, tmp, key)) != NULL)
		return (tmp);
    return (ft_strdup("\0"));
}

static char 	*return_quote(t_msh *msh, char *str)
{
	char 	*first_step;
	char 	*second_step;

	msh->utils->pos++;
	first_step = NULL;
	while (str[msh->utils->pos] && str[msh->utils->pos] != msh->utils->quote)
	{
		second_step = NULL;
		if (msh->utils->quote == DQUOTE && str[msh->utils->pos] == '\\'
		&& (str[msh->utils->pos + 1] == '$'
		|| str[msh->utils->pos + 1] == DQUOTE
		|| str[msh->utils->pos + 1] == '\\'))
			msh->utils->pos++;
		else if (str[msh->utils->pos] == '$' && msh->utils->quote == DQUOTE
		&& (str[msh->utils->pos + 1] != msh->utils->quote
		|| str[msh->utils->pos + 1] != '\\'))
			second_step = return_dollar(msh, str, YESQUOTE);
		else if ((str[msh->utils->pos] != msh->utils->quote)
		&& str[msh->utils->pos + 1])
			second_step = ft_substr(str, msh->utils->pos, 1);
		first_step = ft_strjoin(first_step, second_step);
		if (second_step)
			free(second_step);
		if (str[msh->utils->pos])
			msh->utils->pos++;
	}
	return (first_step);
}

char		*return_all_content(t_msh *msh, char *str)
{
	char 	*first_step;
	char 	*second_step;

	msh->utils->pos = 0;
	first_step = NULL;
	while (str[msh->utils->pos++])
	{
		second_step = NULL;
		if (str[msh->utils->pos] == DQUOTE || str[msh->utils->pos] == SQUOTE)
		{
			msh->utils->quote = str[msh->utils->pos];
			second_step = return_quote(msh, str);
		}
		else if (str[msh->utils->pos] == '$')
			second_step = return_dollar(msh, str, NOQUOTE);
		else
			second_step = ft_substr(str, msh->utils->pos, 1);
		msh->utils->no_space = 1;
		first_step = ft_strjoin(first_step, second_step);
		if (second_step)
			free(second_step);
		// if (str[msh->utils->pos])
		// 	msh->utils->pos++;
	}
	free(str);
	return (first_step);
}
