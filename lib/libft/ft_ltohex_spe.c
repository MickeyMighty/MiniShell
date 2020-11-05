/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltohex_spe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:14:11 by loamar            #+#    #+#             */
/*   Updated: 2019/11/30 19:36:01 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		ft_neg(long num, char *base)
{
	long		max;

	max = 4294967295;
	num = max - num + 1;
	return (num);
}

static long		ft_len(long num)
{
	long		len;

	len = 0;
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}

char			*ft_ltohex_spe(long num)
{
	char		*stock;
	char		*base;
	t_num		p;

	p.tmp = 4294967295;
	base = ft_strdup("0123456789abcdef");
	p.len = 0;
	num = ft_neg(-num, base);
	p.len = ft_len(num) * 2;
	if (!(stock = (char *)malloc(sizeof(char) * p.len + 1)))
		return (NULL);
	p.pos = 1;
	while (p.tmp != 0)
	{
		stock[p.len - p.pos++] = base[p.tmp % 16];
		p.tmp /= 16;
	}
	while (num != 0)
	{
		stock[p.len - p.pos++] = base[num % 16];
		num /= 16;
	}
	stock[p.len] = '\0';
	free(base);
	return (stock);
}
