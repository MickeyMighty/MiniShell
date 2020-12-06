/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:43:48 by loamar            #+#    #+#             */
/*   Updated: 2020/12/06 05:27:59 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static void		ft_count_word(char *s, char c, t_split_data *data)
{
	data->pos = 0;
	data->nb = 0;
	while (s[data->pos] != '\0')
	{
		while (s[data->pos] == c)
			data->pos++;
		if (s[data->pos] != '\0' && s[data->pos] != c)
		{
			if (s[data->pos] == SQUOTE || s[data->pos] == DQUOTE)
				ft_count_word_quote(s, c, data);
			else
				ft_count_word_noquote(s, c, data);
		}
	}
}

static size_t	ft_get_len_word(char *s, char c, t_split_data *data)
{
	size_t	len_word;
	int 	index;

	index = data->pos;
	len_word = 0;
	if (data->check == 0)
	{
		if (ft_count_separator(s, data->pos) != 0)
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
	else if (data->check == 1 || data->check == 2)
		return (ft_get_len_word_quote(s, c, data, index));
	return (len_word);
}

static char		**ft_free_tab(char **tab, int j, t_split_data *data)
{
	while (j-- >= 0)
		free(tab[j]);
	free(tab);
	free (data);
	return (NULL);
}

static void 		ft_put_pos(char *s, char c, t_split_data *data)
{
	if (data->check == 0)
	{
		if (ft_count_separator(s, data->pos) != 0)
			data->pos += ft_count_separator(s, data->pos);
		else
			while (s[data->pos] != '\0' && s[data->pos] != c && (ft_count_separator(s, data->pos) == 0))
				data->pos++;
	}
	else if (data->check == 1)
	{
		data->pos++;
		while (s[data->pos] != '\0' && s[data->pos] != SQUOTE)
			data->pos++;
	}
	else if (data->check == 2)
	{
		data->pos++;
		while (s[data->pos] != '\0' && s[data->pos] != DQUOTE)
			data->pos++;
	}
	if (s[data->pos] == SQUOTE || s[data->pos] == DQUOTE)
		data->pos++;
}

static int  	ft_put_word_to_tab(char *s, char c, t_split_data *data
, char **res)
{
	while (s[data->pos] != '\0' && data->word < data->nb)
	{
		data->check = 0;
		while (s[data->pos] == c)
			data->pos++;
		if (s[data->pos] != '\0' && s[data->pos] != c)
		{
			check_quote(s, data);
			if (!(res[data->word] = ft_substr(s, data->pos, ft_get_len_word(s, c, data))))
				return (0);
			data->word++;
			ft_put_pos(s, c, data);
		}
	}
	return (1);
}

char			**ft_split_data(char *s, char c)
{
	char	**res;
	int		nb_word;
	t_split_data	*data;

	if (!(data = (t_split_data*)malloc(sizeof(t_split_data))))
		return (NULL);
	ft_count_word(s, c, data);
	if (!s || !(res = (char **)malloc((data->nb + 1) * sizeof(char *))))
		return (NULL);
	data->pos = 0;
	data->word = 0;
	if (ft_put_word_to_tab(s, c, data, res) == 0)
		return (ft_free_tab(res, data->word, data));
	res[data->word] = 0;
	free (data);
	return (res);
}
