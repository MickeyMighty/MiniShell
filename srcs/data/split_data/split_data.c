/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:36:18 by loamar            #+#    #+#             */
/*   Updated: 2021/03/22 17:16:02 by loamar           ###   ########.fr       */
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
		printf("->res[%s]\n", res[split_data->nb]);
		split_data->pos_index = 0;
		while (str[split_data->pos] != '\0' && str[split_data->pos] == ' ')
			split_data->pos++;
		res[split_data->nb] = ft_substr(str, split_data->pos,
		ft_get_len_word(split_data, str));
		printf("->res[%s]\n", res[split_data->nb]);
		split_data->nb++;
		split_data->pos = split_data->pos_index;
		if (res[split_data->nb] == NULL && split_data->error == 1)
			return (NULL);
		// if (split_data->error == 1)
	}
	printf("->res[%s]\n", res[0]);
	printf("->res[%s]\n", res[1]);
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
}

char			**ft_split_data(t_msh *msh, char *s, char c)
{
	char	**res;
	t_split_data	*split_data;

	if (!s)
		return (NULL);
	if (!(split_data = (t_split_data*)malloc(sizeof(t_split_data))))
		return (NULL);
	printf("hey\n");
	split_data->error = 0;
	split_data->nb_word = 0;
	split_data->pos = 0;
	printf("hey 2\n");
	ft_count_word(msh ,s, c, split_data);
	if (split_data->error == 1)
		return (NULL);
	printf("hey 3\n");
	if (!(res = (char **)malloc(sizeof(char *) * (split_data->nb_word + 1))))
		return (NULL);
	printf("hey 4\n");
	split_data->pos = 0;
	printf("hey 5\n");
	res = ft_word_to_tab(msh, s, split_data, res);
	printf("hey 6\n");
	if (res == NULL)
	{
		printf("hey 7\n");
		// ft_free_tab(res, split_data->nb_word, split_data);
		return (NULL);
	}
	printf("hey 8\n");
	printf("hey 9\n");
	free (split_data);
	printf("res[0] = [%s]\n", res[0]);
	printf("res[0] = [%s]\n", res[1]);
	printf("hey 10\n");
	return (res);
}
