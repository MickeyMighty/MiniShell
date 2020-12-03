/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:43:48 by loamar            #+#    #+#             */
/*   Updated: 2020/12/03 16:32:44 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int		ft_count_word(char const *s, char c)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			if (s[i] == 34 || s[i] == 39)
				nb = ft_count_word_quote(s, c, i, nb);
			else
				nb = ft_count_word_noquote(s, c, i, nb);
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (nb);
}

static size_t	ft_get_len_word(const char *s, int index, char c, int check)
{
	size_t	len_word;

	len_word = 0;
	if (check == 1)
	{
		if (ft_count_seprator(s, i) != 0)
			len_word = ft_count_seprator(s, i);
		else
		{
			while (s[index] != '\0' && s[index] == c
			&& (ft_count_seprator(s, i) == 0))
			{
				len_word++;
				index++;
			}
		}
	}
	else
	{
		while (s[index] != '\0' && s[index] != c)
		{
			len_word++;
			index++;
		}
	}
	return (len_word);
}

static char		**free_tab(char **tab, int j)
{
	while (j-- >= 0)
		free(tab[j]);
	free(tab);
	return (NULL);
}

static int 		ft_put_pos(char *s, int check, int pos)
{
	if (check == 1)
	{
		if (ft_count_seprator(s, pos) != 0)
			pos = ft_count_seprator(s, pos);
		else
			while (s[i] != '\0' && s[i] != c && (ft_count_seprator(s, pos) == 0))
				pos++;
	}
	else
		while (s[pos] != '\0' && s[pos] != c)
			pos++;
	return (pos);
}

char			**ft_split(char *s, char c)
{
	char	**res;
	int		nb_word;
	int		i;
	int		j;
	int 	check;

	nb_word = ft_count_word(s, c);
	if (!s || !(res = (char **)malloc((nb_word + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0' && j < nb_word)
	{
		check = 0;
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			if (s[i] == 34 || s[i] == 39)
				check = 1;
			if (!(res[j] = ft_substr(s, i, ft_get_len_word(s, i, c, check))))
				return (free_tab(res, j));
			j++;
			i = ft_put_pos(s, check, i);
		}
	}
	res[j] = 0;
	return (res);
}
