/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:48:58 by loamar            #+#    #+#             */
/*   Updated: 2021/03/24 20:42:29 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

// int			check_data(char *str, char c, int pos)
// {
// 	while (str[pos] && str[pos] != c)
// 		pos++;
// 	if (str[pos] == c)
// 		return (SUCCESS);
// 	else
// 		return (ERROR);
// }

// char 		*return_value_data(char *str, int pos)
// {
//
// }

int 	handler_data(t_msh *msh, char *buf) // mettre en void
{
	global_error_msg = 0;

	msh->data->size_data = 0;
	msh->data->prompt_data = ft_split_data(msh, buf, ' ');
	if (msh->data->prompt_data == NULL)
	{
		if (global_error_msg == 0)
			return (ERROR);
		else if (global_error_msg == 1)
			return(return_error(msh, NULL,"syntax error multiligne."));
	}
	ft_memset(buf, 0, ft_strlen(buf));
	free(buf);
	msh->data->size_data = global_size_word;
	// ft_size_data(msh, buf);
	return (SUCCESS);
}
