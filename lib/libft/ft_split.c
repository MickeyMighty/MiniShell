/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:19:45 by loamar            #+#    #+#             */
/*   Updated: 2020/01/19 18:02:28 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_count_word(char const *s, char c)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i] != '\0' && s[i] != c)
		{
			nb++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (nb);
}

static size_t	ft_get_len_word(const char *s, int index, char c)
{
	size_t	len_word;

	len_word = 0;
	while (s[index] != '\0' && s[index] != c)
	{
		len_word++;
		index++;
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

char			**ft_split(char *s, char c)
{
	char	**res;
	int		nb_word;
	int		i;
	int		j;

	nb_word = ft_count_word(s, c);
	if (!s || !(res = (char **)malloc((nb_word + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0' && j < nb_word)
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			if (!(res[j] = ft_substr(s, i, ft_get_len_word(s, i, c))))
				return (free_tab(res, j));
			j++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	res[j] = 0;
	return (res);
}
