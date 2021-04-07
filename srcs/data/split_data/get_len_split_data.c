/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len_split_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzoa <lorenzoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:32:35 by lorenzoa          #+#    #+#             */
/*   Updated: 2021/04/07 13:33:16 by lorenzoamar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

static	int		get_pos_word(char *str, t_split_data *split_data, int index)
{
	if (str[index] == '\\' && str[index + 1])
		index++;
	else if (str[index] == '\\' && str[index + 1] == '\0')
		split_data->error = 1;
	else if (str[index] == SQUOTE || str[index] == DQUOTE)
		index = ft_size_quote(split_data, str, index);
	if (str[index])
		index++;
	return (index);
}

int				ft_get_len_word(t_split_data *split_data, char *str)
{
	int		index;

	index = split_data->pos;
	if (!str[index])
		return (0);
	if (ft_count_separator(split_data, str, index) != 0)
	{
		split_data->pos_index = index +
			ft_count_separator(split_data, str, index);
		index = ft_count_separator(split_data, str, index);
		return (index);
	}
	while (str[index] != '\0' && str[index] != ' '
			&& ft_count_separator(split_data, str, index) == 0)
		index = get_pos_word(str, split_data, index);
	split_data->pos_index = index;
	return (index - split_data->pos);
}
