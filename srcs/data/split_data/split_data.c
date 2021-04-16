/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:36:18 by loamar            #+#    #+#             */
/*   Updated: 2021/04/16 13:28:04 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

static	void	to_tab(char *str,
t_split_data *split_data, char **res)
{
	split_data->pos_index = 0;
	while (str[split_data->pos] != '\0' && str[split_data->pos] == ' ')
		split_data->pos++;
	res[split_data->nb] = ft_substr(str, split_data->pos,
	ft_get_len_word(split_data, str));
	split_data->nb++;
	split_data->pos = split_data->pos_index;
}

char			**ft_word_to_tab(char *str,
t_split_data *split_data, char **res)
{
	int		i;
	int		loop;

	i = 0;
	loop = 0;
	split_data->nb = 0;
	split_data->error = 0;
	while (str[split_data->pos] && (split_data->nb < split_data->nb_word))
	{
		loop++;
		to_tab(str, split_data, res);
		if (res[split_data->nb - 1] == NULL && split_data->error == 1)
		{
			while (i < split_data->nb_word && i < loop)
			{
				free(res[i]);
				i++;
			}
			return (NULL);
		}
	}
	return (res);
}

static	int		get_pos_after_word(char *s, char c,
t_split_data *split_data)
{
	split_data->nb_word++;
	if (s[split_data->pos] == '\\' && s[split_data->pos + 1] == c)
		split_data->pos += 2;
	while (s[split_data->pos] != '\0' && s[split_data->pos] != c
	&& (ft_count_separator(split_data, s, split_data->pos) == 0))
	{
		if ((split_data->pos = check_word_qte(split_data, s)) == ERROR)
			return (-1);
		else if (s[split_data->pos] == '\\' && s[split_data->pos + 1])
			split_data->pos++;
		if (s[split_data->pos])
			split_data->pos++;
	}
	return (1);
}

void			ft_count_word(t_msh *msh, char *s, char c,
t_split_data *split_data)
{
	while (s[split_data->pos])
	{
		while (s[split_data->pos] == c)
			split_data->pos++;
		if (s[split_data->pos] != '\0' && s[split_data->pos] != c
		&& (ft_count_separator(split_data, s, split_data->pos) == 0))
			if (get_pos_after_word(s, c, split_data) == -1)
				return ;
		split_data->double_semicolon = 0;
		if (s[split_data->pos] && ft_count_separator(split_data, s,
			split_data->pos) != 0)
		{
			split_data->nb_word++;
			if (split_data->double_semicolon == 1 && s[split_data->pos + 1])
				if (ft_count_separator(split_data, s, (split_data->pos + 1))
				== 1)
					if (split_data->double_semicolon == 2)
						split_data->error = 2;
			split_data->pos += ft_count_separator(split_data, s,
				split_data->pos);
		}
		else if (s[split_data->pos] != '\0')
			split_data->pos++;
	}
	msh->data->size_data = split_data->nb_word;
}
