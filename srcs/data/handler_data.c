/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:48:58 by loamar            #+#    #+#             */
/*   Updated: 2021/03/21 11:11:32 by loamar           ###   ########.fr       */
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

static void 	ft_size_data(t_msh *msh, char *buf)
{
	msh->data->size_data = 0;
	ft_memset(buf, 0, ft_strlen(buf));
	free(buf);
	while (msh->data->prompt_data[msh->data->size_data] != NULL)
		msh->data->size_data++;
}

int 	handler_data(t_msh *msh, char *buf) // mettre en void
{
	msh->data->prompt_data = ft_split_data(msh, buf, ' ');
	if (msh->data->prompt_data == NULL)
		return(return_error(msh, NULL,"syntax error multiligne."));
	ft_size_data(msh, buf);
	return (SUCCESS);
}
