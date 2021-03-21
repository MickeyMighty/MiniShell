/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_data_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:43:38 by loamar            #+#    #+#             */
/*   Updated: 2021/03/17 09:47:47 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

int		ft_count_separator(char *s, int pos)
{
	if (s[pos + 1])
		if ((s[pos] == '>' || s[pos + 1] == '>'))
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
