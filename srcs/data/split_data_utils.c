/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_data_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:00:26 by loamar            #+#    #+#             */
/*   Updated: 2020/12/03 17:10:19 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int		ft_count_separator(char const *s, int pos)
{
	if ((s[pos] == '|' && s[pos + 1] == '|')
	|| (s[pos] == '>' ||s[pos] == '>') || (s[pos] == '&' || s[pos] == '&'))
		return (2);
	else if (s[pos] == ';' || s[pos] == '|' || s[pos] == '<' || s[pos] == '>'
	|| s[pos] == '&')
		return (1);
	else
		return (0);
}

int 	ft_count_word_noquote(char const *s, char c, int i, int nb)
{
	if (ft_count_separator(s, i) == 0)
		nb++;
	while (s[i] != '\0' && s[i] != c)
	{
		if (ft_count_separator(s, i) != 0) // probleme pour le ft_count_seprator && (+1)
			nb++;
		i++;
	}
	return (nb);
}

int 	ft_count_word_quote(char const *s, char c, int i, int nb)
{
	nb++;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (nb);
}
