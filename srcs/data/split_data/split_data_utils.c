/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_data_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:00:26 by loamar            #+#    #+#             */
/*   Updated: 2020/12/06 07:12:12 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

void 	check_quote(char *s, t_split_data *data)
{
	if (s[data->pos] == SQUOTE)
		data->check = 1;
	else if (s[data->pos] == DQUOTE)
		data->check = 2;
	else
		data->check = 0;
}

int		ft_count_separator(char *s, int pos)
{
	if ((s[pos] == '|' && s[pos + 1] == '|')
	|| (s[pos] == '>' ||s[pos] == '>') || (s[pos] == '&' || s[pos] == '&'))
		return (2);
	else if (s[pos] == ';' || s[pos] == '|' || s[pos] == '<' || s[pos] == '>'
	|| s[pos] == '&')
		return (1);
	else
		return (0);
}

void 	ft_count_word_quote(char *s, char c, t_split_data *data)
{
	data->nb++;
	if (s[data->pos] == SQUOTE)
	{
		data->pos++;
		while (s[data->pos] != '\0' && s[data->pos] != SQUOTE)
			data->pos++;
		if (s[data->pos] == SQUOTE)
			data->pos++;
	}
	else if (s[data->pos] == DQUOTE)
	{
		data->pos++;
		while (s[data->pos] != '\0' && s[data->pos] != DQUOTE)
			data->pos++;
		if (s[data->pos] == DQUOTE)
			data->pos++;
	}
}

void 	ft_count_word_noquote(char *s, char c, t_split_data *data)
{
	if (ft_count_separator(s, data->pos) != 0)
	{
		data->nb++;
		if (ft_count_separator(s, data->pos) != 0)
			data->pos += ft_count_separator(s, data->pos);
	}
	else
	{
		data->nb++;
		while (s[data->pos] != '\0' && s[data->pos] != c
		&& (ft_count_separator(s, data->pos) == 0))
			data->pos++;
	}
}

int 	ft_get_len_word_quote(char *s, char c, t_split_data *data, int index)
{
	int 	len_word;

	len_word = 0;
	index++;
	len_word++;
	if (data->check == 1)
	{
		while (s[index] != '\0' && (s[index] != SQUOTE))
		{
			len_word++;
			index++;
		}
	}
	else
	{
		while (s[index] != '\0' && (s[index] != DQUOTE))
		{
			len_word++;
			index++;
		}
	}
	if (s[index] == SQUOTE || s[index] == DQUOTE)
		len_word++;
	return (len_word);
}
