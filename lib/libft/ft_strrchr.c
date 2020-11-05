/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:22:28 by loamar            #+#    #+#             */
/*   Updated: 2019/11/29 16:22:30 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (s[len] == c)
		return ((char *)(s + len));
	while (len > 0)
	{
		if (s[len - 1] == c)
			return ((char *)(s + len - 1));
		len--;
	}
	return (0);
}
