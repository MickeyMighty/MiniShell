/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_data_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:00:26 by loamar            #+#    #+#             */
/*   Updated: 2021/03/08 20:48:45 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

void 	check_quote(char *s, t_split_data *split_data)
{
	if (s[split_data->pos] == SQUOTE)
		split_data->check = 1;
	else if (s[split_data->pos] == DQUOTE)
		split_data->check = 2;
	else
		split_data->check = 0;
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

void 	ft_count_word_quote(char *s, char c, t_split_data *split_data)
{
	(void)c;
	split_data->nb++;
	if (s[split_data->pos] == SQUOTE)
	{
		split_data->pos++;
		while (s[split_data->pos] != '\0' && s[split_data->pos] != SQUOTE)
			split_data->pos++;
		if (s[split_data->pos] == SQUOTE)
			split_data->pos++;
	}
	else if (s[split_data->pos] == DQUOTE)
	{
		split_data->pos++;
		while (s[split_data->pos] != '\0' && s[split_data->pos] != DQUOTE)
			split_data->pos++;
		if (s[split_data->pos] == DQUOTE)
			split_data->pos++;
	}
}

void 	ft_count_word_noquote(char *s, char c, t_split_data *split_data)
{
	if (ft_count_separator(s, split_data->pos) != 0)
	{
		split_data->nb++;
		if (ft_count_separator(s, split_data->pos) != 0)
			split_data->pos += ft_count_separator(s, split_data->pos);
	}
	else
	{
		split_data->nb++;
		while (s[split_data->pos] != '\0' && s[split_data->pos] != c
		&& (ft_count_separator(s, split_data->pos) == 0))
			split_data->pos++;
	}
}

int 	ft_get_len_word_quote(char *s, char c, t_split_data *split_data, int index)
{
	int 	len_word;

	(void)c;
	len_word = 0;
	index++;
	len_word++;
	if (split_data->check == 1)
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
