/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:48:58 by loamar            #+#    #+#             */
/*   Updated: 2021/04/11 22:58:33 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int				get_split_pos(char *str, t_split_data *split_data, int index)
{
	index++;
	while (str[index] && str[index] != DQUOTE)
	{
		if (str[index] == '\\' && str[index + 1])
			index++;
		else if (str[index] == '\\' && str[index + 1] == DQUOTE)
			index++;
		else if (str[index] == '\\' && !str[index + 1])
		{
			split_data->error = 1;
			return (-1);
		}
		index++;
	}
	return (index);
}

char			**ft_split_data(t_split_data *split_data, char *s, char c)
{
	char			**res;

	if (!s || s[0] == '\0' || s == NULL)
		return (NULL);
	if (check_word(s, c) == 0)
		ft_count_word(s, c, split_data);
	else
		return (NULL);
	if (split_data->error == 1)
		return (NULL);
	if (split_data->error == 2)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (split_data->nb_word))))
		return (NULL);
	split_data->pos = 0;
	res = ft_word_to_tab(s, split_data, res);
	if (res == NULL)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

int				get_value_sep(char *str)
{
	if (ft_strcmp(str, "|") == 0)
		return (PIPE);
	else if (ft_strcmp(str, "<") == 0 || ft_strcmp(str, ">") == 0
	|| ft_strcmp(str, ">>") == 0)
		return (REDIR);
	else if (ft_strcmp(str, ";") == 0)
		return (SEMICOLON);
	else
		return (0);
}

int				main(int argc, char **argv)
{
	int		i;
	char	**res;

	i = 0;
	(void)argc;
	t_split_data	*split_data;
	split_data = init_split_data(split_data);
	res = ft_split_data(split_data, argv[1], ' ');
	while (i < split_data->nb_word)
	{
		printf("res[%d][%s]\n", i, res[i]);
		free(res[i]);
		i++;
	}
	free(split_data);
}
