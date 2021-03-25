/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:36:18 by loamar            #+#    #+#             */
/*   Updated: 2021/03/24 20:41:30 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

static int 	ft_size_quote(t_split_data *split_data, char *str, int index)
{
	char	quote;

	quote = str[index];
	index++;
	while (str[index])
	{
		if (str[index] == quote && quote == SQUOTE)
			return (index);
		if (str[index] == quote  && str[index - 1] != '\\' && quote == DQUOTE)
			return (index);
		index++;
	}
	split_data->error = 1;
	return (index);
}

static 		int ft_get_len_word(t_split_data *split_data, char *str)
{
	int		index;

	index = 0;
	index = split_data->pos;
	if (!str[index])
		return (0);
	if (ft_count_separator(str, index) != 0)
	{
		split_data->pos_index = index + ft_count_separator(str, index);
		index = ft_count_separator(str, index);
		return (index);
	}
	while (str[index] != '\0' && str[index] != ' '
	&& ft_count_separator(str, index) == 0)
	{
		if (str[index] == '\\' && (index + 1) == ft_strlen(str))
			split_data->error = 1;
		if (str[index] == SQUOTE || str[index] == DQUOTE)
			index = ft_size_quote(split_data, str, index);
		if (str[index] && str[index] != ' ')
			index++;
	}
	split_data->pos_index = index;
	return (index - split_data->pos);
}

static char		**ft_word_to_tab(t_msh *msh, char *str, t_split_data *split_data,
char **res)
{
	split_data->nb = 0;
	split_data->error = 0;
	while (str[split_data->pos] && (split_data->nb < split_data->nb_word))
	{
		split_data->pos_index = 0;
		while (str[split_data->pos] != '\0' && str[split_data->pos] == ' ')
			split_data->pos++;
		res[split_data->nb] = ft_substr(str, split_data->pos,
		ft_get_len_word(split_data, str));
		split_data->nb++;
		split_data->pos = split_data->pos_index;
		if (res[split_data->nb] == NULL && split_data->error == 1)
			return (NULL);
	}
	return (res);
}

void 			ft_count_word(t_msh *msh, char *s, char c,
t_split_data *split_data)
{
	while (s[split_data->pos])
	{
		while (s[split_data->pos] == c)
			split_data->pos++;
		if (s[split_data->pos] != '\0' && s[split_data->pos] != c
		&& (ft_count_separator(s, split_data->pos) == 0))
		{
			split_data->nb_word++;
			while (s[split_data->pos] != '\0' && s[split_data->pos] != c
			&& (ft_count_separator(s, split_data->pos) == 0))
			{
				if ((split_data->pos = ft_check_word(msh, split_data, s)) == ERROR)
					return ;
				split_data->pos++;
			}
		}
		if (s[split_data->pos] && ft_count_separator(s, split_data->pos) != 0)
		{
			split_data->nb_word++;
			split_data->pos += ft_count_separator(s, split_data->pos);
		}
		else if (s[split_data->pos] != '\0')
			split_data->pos++;
	}
	global_size_word = split_data->nb_word;
}

char			**ft_split_data(t_msh *msh, char *s, char c)
{
	char			**res;
	t_split_data	*split_data;

	split_data = init_split_data(split_data, s);
	if (split_data == NULL)
		return (NULL);
	if (check_word(split_data, s, c) == 0)
		ft_count_word(msh ,s, c, split_data);
	else
		return (NULL);
	if (split_data->error == 1)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (split_data->nb_word + 1))))
		return (NULL);
	split_data->pos = 0;
	res = ft_word_to_tab(msh, s, split_data, res);
	if (res == NULL)
	{
		global_error_msg = 1;
		free(res);
		free(split_data);
		return (NULL);
	}
	free(split_data);
	return (res);
}
