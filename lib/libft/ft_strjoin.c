/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:20:33 by loamar            #+#    #+#             */
/*   Updated: 2021/03/16 23:54:04 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int 		check(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (-1);
	if (!s1)
		return (-1);
	if (!s2)
		return (-1);
	return (0);
}

static char		*return_error(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (ft_strdup("\0"));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	return (NULL);
}

char			*ft_strjoin(char *s1, char *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*dest;
	int		i;

	if (check(s1, s2) == -1)
		return (return_error(s1, s2));
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(dest = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1))))
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		dest[i + lens1] = s2[i];
		i++;
	}
	dest[i + lens1] = '\0';
	return (dest);
}
