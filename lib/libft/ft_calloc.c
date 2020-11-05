/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:09:16 by loamar            #+#    #+#             */
/*   Updated: 2019/11/29 16:09:20 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	if (count * size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(dest = (void *)malloc(size * count)))
		return (0);
	ft_memset(dest, '\0', size * count);
	return (dest);
}
