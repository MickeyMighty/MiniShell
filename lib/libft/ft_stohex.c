/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:19:55 by loamar            #+#    #+#             */
/*   Updated: 2019/11/29 16:19:58 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_neg(long int num, char *base)
{
	long int	max;

	max = 4294967295;
	num = max - num + 1;
	return (num);
}

static long int	ft_len(long int num)
{
	long int	len;

	len = 0;
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}

char			*ft_stohex(char *str)
{
	long int	num;
	long int	pos;
	long int	len;
	char		*stock;
	char		*base;

	base = ft_strdup("0123456789abcdef");
	len = 0;
	num = ft_atoi(str);
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
