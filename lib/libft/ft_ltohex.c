/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:13:54 by loamar            #+#    #+#             */
/*   Updated: 2019/11/29 16:14:03 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_neg(long num, char *base)
{
	long max;

	max = 4294967295;
	num = max - num + 1;
	return (num);
}

static long	ft_len(long num)
{
	long len;

	len = 0;
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}

char		*ft_ltohex(long num)
{
	long pos;
	long len;
	char *stock;
	char *base;

	base = ft_strdup("0123456789abcdef");
	len = 0;
	if (num < 0)
		num = ft_neg(-num, base);
	if (num == 0)
		return ("0");
	len = ft_len(num);
	if (!(stock = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	pos = 1;
	while (num != 0)
	{
		stock[len - pos++] = base[num % 16];
		num /= 16;
	}
	stock[len] = '\0';
	free(base);
	return (stock);
}
