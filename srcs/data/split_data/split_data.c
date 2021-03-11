/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:43:48 by loamar            #+#    #+#             */
/*   Updated: 2021/03/11 14:49:41 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

static void		ft_count_word(char *s, char c, t_split_data *split_data)
{
	split_data->pos = 0;
	split_data->nb = 0;
	while (s[split_data->pos] != '\0')
	{
		while (s[split_data->pos] == c)
			split_data->pos++;
		if (s[split_data->pos] != '\0' && s[split_data->pos] != c)
		{
			if (s[split_data->pos] == SQUOTE || s[split_data->pos] == DQUOTE)
				ft_count_word_quote(s, c, split_data);
			else
				ft_count_word_noquote(s, c, split_data);
		}
	}
}

static size_t	ft_get_len_word(char *s, char c, t_split_data *split_data)
{
	size_t	len_word;
	int 	index;

	index = split_data->pos;
	len_word = 0;
	if (split_data->check == 0)
	{
		if (ft_count_separator(s, split_data->pos) != 0)
			len_word = ft_count_separator(s, index);
		else
		{
			while (s[index] != '\0' && s[index] != c
			&& (ft_count_separator(s, index) == 0))
			{
				len_word++;
				index++;
			}
		}
		return (len_word);
	}
	else if (split_data->check == 1 || split_data->check == 2)
		return (ft_get_len_word_quote(s, c, split_data, index));
	return (len_word);
}

static void 		ft_put_pos(char *s, char c, t_split_data *split_data)
{
	if (split_data->check == 0)
	{
		if (ft_count_separator(s, split_data->pos) != 0)
			split_data->pos += ft_count_separator(s, split_data->pos);
		else
			while (s[split_data->pos] != '\0' && s[split_data->pos] != c && (ft_count_separator(s, split_data->pos) == 0))
				split_data->pos++;
	}
	else if (split_data->check == 1)
	{
		split_data->pos++;
		while (s[split_data->pos] != '\0' && s[split_data->pos] != SQUOTE)
			split_data->pos++;
	}
	else if (split_data->check == 2)
	{
		split_data->pos++;
		while (s[split_data->pos] != '\0' && s[split_data->pos] != DQUOTE)
			split_data->pos++;
	}
	if (s[split_data->pos] == SQUOTE || s[split_data->pos] == DQUOTE)
		split_data->pos++;
}

static char  	**ft_put_word_to_tab(char *s, char c, t_split_data *split_data, char **res)
{
	while (s[split_data->pos] != '\0' && split_data->word < split_data->nb)
	{
		split_data->check = 0;
		while (s[split_data->pos] == c)
			split_data->pos++;
		if (s[split_data->pos] != '\0' && s[split_data->pos] != c)
		{
			check_quote(s, split_data);
			res[split_data->word] = ft_substr(s, split_data->pos,
			ft_get_len_word(s, c, split_data));
			if (res[split_data->word] == NULL)
				return (NULL);
			split_data->word++;
			ft_put_pos(s, c, split_data);
		}
	}
	return (res);
}

char			**ft_split_data(char *s, char c)
{
	char	**res;
	t_split_data	*split_data;

	if (!(split_data = (t_split_data*)malloc(sizeof(t_split_data))))
		return (NULL);
	ft_count_word(s, c, split_data);
	if (!s || !(res = (char **)malloc((split_data->nb + 1) * sizeof(char *))))
		return (NULL);
	split_data->pos = 0;
	split_data->word = 0;
	res = ft_put_word_to_tab(s, c, split_data, res);
	if (res == NULL)
		return (ft_free_tab(res, split_data->word, split_data));
	res[split_data->word] = 0;
	free (split_data);
	return (res);
}
