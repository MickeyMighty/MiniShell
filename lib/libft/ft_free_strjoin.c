/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 23:57:55 by loamar            #+#    #+#             */
/*   Updated: 2021/04/05 12:08:58 by lorenzoamar      ###   ########.fr       */
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

static char		*return_error(char *s1, char *s2, int free1, int free2)
{
	if (!s1 && !s2)
		return (ft_strdup("\0"));
	if (!s1 && free2 == 0)
		return (ft_strdup(s2));
	if (!s2 && free1 == 0)
		return (ft_strdup(s1));
	if (!s1 && free2 == 1)
		return (s2);
	if (!s2 && free1 == 1)
		return (s1);
	return (NULL);
}

char			*ft_free_strjoin(char *s1, char *s2, int free1, int free2)
{
	size_t	lens1;
	size_t	lens2;
	char	*dest;
	int		i;

	if (check(s1, s2) == -1)
		return (return_error(s1, s2, free1, free2));
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
	if (free1 == 1)
		free(s1);
	if (free2 == 1)
		free(s2);
	dest[i + lens1] = '\0';
	return (dest);
}
