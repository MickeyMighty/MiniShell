/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_global_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:51:26 by loamar            #+#    #+#             */
/*   Updated: 2021/04/26 21:56:46 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int		g_bytes(int mode, int value)
{
	static int	bytes;

	if (mode == 1)
		bytes = value;
	return (bytes);
}
