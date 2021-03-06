/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_data_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:43:38 by loamar            #+#    #+#             */
/*   Updated: 2021/04/15 13:53:28 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

int				check_word(char *s, char c)
{
	int		pos;

	pos = 0;
	while (s[pos] == c)
		pos++;
	if (s[pos] == '\0')
		return (1);
	else
		return (0);
}

t_split_data	*init_split_data(t_split_data *split_data)
{
	if (!(split_data = (t_split_data*)malloc(sizeof(t_split_data))))
		return (NULL);
	split_data->error = 0;
	split_data->size = 0;
	split_data->double_semicolon = 0;
	split_data->nb_word = 0;
	split_data->nb = 0;
	split_data->pos_index = 0;
	split_data->pos = 0;
	return (split_data);
}

int				ft_count_separator(t_split_data *split_data, char *s, int pos)
{
	if (s[pos + 1])
		if ((s[pos] == '>' && s[pos + 1] == '>'))
			return (2);
	if (s[pos] == ';' || s[pos] == '|' || s[pos] == '<' || s[pos] == '>')
	{
		if (s[pos] == ';')
		{
			if (split_data->double_semicolon == 0)
				split_data->double_semicolon = 1;
			else if (split_data->double_semicolon == 1)
				split_data->double_semicolon = 2;
		}
		return (1);
	}
	return (0);
}

static	int		check_word_squote(t_split_data *split_data, char *str,
int index)
{
	index++;
	while (str[index] && str[index] != SQUOTE)
		index++;
	if (str[index] == SQUOTE)
		return (index);
	split_data->error = 1;
	return (index);
}

int				check_word_qte(t_split_data *split_data, char *str)
{
	int		index;

	index = split_data->pos;
	if (str[index] == SQUOTE)
		return (check_word_squote(split_data, str, index));
	else if (str[index] == DQUOTE)
	{
		index = get_split_pos(str, split_data, index);
		if (index == -1)
			return (ERROR);
		if (str[index] == DQUOTE)
			return (index);
		else
		{
			split_data->error = 1;
			return (ERROR);
		}
	}
	else if ((index == (int)ft_strlen(str)) && str[index - 1] == '\\')
	{
		split_data->error = 1;
		return (ERROR);
	}
	return (index);
}
