/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:56:22 by loamar            #+#    #+#             */
/*   Updated: 2020/11/07 12:24:06 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	error_data(t_data *data, int token)
{
	ft_putstr(data->prompt_data[token]);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	return (1);
}
