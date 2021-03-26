/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_data_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:43:38 by loamar            #+#    #+#             */
/*   Updated: 2021/03/26 10:03:24 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

int 			check_word(t_split_data *split_data, char *s, char c)
{
	int		pos;

	pos = 0;
	while (s[pos] == c)
		pos++;
	if (s[pos] == '\0')
	{
		free(split_data);
		return (1);
	}
	else
		return (0);
}

t_split_data 	*init_split_data(t_split_data *split_data, char *s)
{
	if (!s || s[0] == '\0' || s == NULL)
		return (NULL);
	if (!(split_data = (t_split_data*)malloc(sizeof(t_split_data))))
		return (NULL);
	split_data->error = 0;
	split_data->nb_word = 0;
	split_data->nb = 0;
	split_data->pos_index = 0;
	split_data->pos = 0;
	return (split_data);
}

int		ft_count_separator(char *s, int pos)
{
	if (s[pos + 1])
		if ((s[pos] == '>' && s[pos + 1] == '>'))
			return (2);
	if (s[pos] == ';' || s[pos] == '|' || s[pos] == '<' || s[pos] == '>')
		return (1);
	return (0);
}

static int  check_word_squote(t_split_data *split_data, char *str, int index)
{
	index++;
	while (str[index] && str[index] != SQUOTE)
		index++;
	if (str[index] == SQUOTE)
		return (index);
	split_data->error = 1;
	return (index);
}

int 	ft_check_word(t_msh *msh, t_split_data *split_data, char *str)
{
	int 	index;

	index = split_data->pos;
	if (str[index] == SQUOTE)
		return (check_word_squote(split_data, str, index));
	else if (str[index] == DQUOTE)
	{
		index++;
		while (str[index] && str[index] != DQUOTE)
			index++;
		if (str[index] == DQUOTE && str[index - 1] != '\\')
			return (index);
		else
			split_data->error = 1;
	}
	else if (index == ft_strlen(str) && str[index - 1] == '\\')
		split_data->error = 1;
	return (index);
}
