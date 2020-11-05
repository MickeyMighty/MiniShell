/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:20:44 by loamar            #+#    #+#             */
/*   Updated: 2019/11/29 16:20:45 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	len_d;
	size_t	i;

	len = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (len);
	len_d = ft_strlen(dst);
	if (dstsize <= len_d)
		return (len + dstsize);
	else
		len += len_d;
	i = 0;
	while (src[i] != '\0' && len_d < dstsize - 1)
	{
		dst[len_d] = src[i];
		i++;
		len_d++;
	}
	dst[len_d] = '\0';
	return (len);
}
