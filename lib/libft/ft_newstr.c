/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:26:50 by loamar            #+#    #+#             */
/*   Updated: 2020/01/14 19:29:05 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_newstr(size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if ((ptr = malloc(sizeof(*ptr) * size + 1)) == NULL)
		return (NULL);
	while (i <= size)
		ptr[i++] = '\0';
	return (ptr);
}
