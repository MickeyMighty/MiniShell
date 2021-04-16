/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 23:57:55 by loamar            #+#    #+#             */
/*   Updated: 2021/04/16 13:55:57 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*return_error(char *s1, char *s2)
{
	char	*tmp;

	if ((!s1 && !s2) || (s1 == NULL && s2 == NULL))
		return (ft_strdup("\0"));
	if (!s1 || s1 == NULL)
		return (s2);
	if (!s2 || s2 == NULL)
		return (s1);
	return (NULL);
}

static int		check(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (-1);
	if (!s1)
		return (-1);
	if (!s2)
		return (-1);
	return (0);
}

static	char	*return_dest(char *s1, char *s2, char *dest, int lens1)
{
	int		i;

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

char			*ft_free_strjoin(char *s1, char *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*dest;

	dest = NULL;
	if (check(s1, s2) == -1)
		return (return_error(s1, s2));
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(dest = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1))))
		return (0);
	dest = return_dest(s1, s2, dest, lens1);
	free(s1);
	free(s2);
	return (dest);
}
