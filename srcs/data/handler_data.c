/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:48:58 by loamar            #+#    #+#             */
/*   Updated: 2021/03/22 17:38:38 by loamar           ###   ########.fr       */
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
	printf("C EST ICI \n");
	msh->data->prompt_data = ft_split_data(msh, buf, ' ');
	printf("___1\n");
	if (msh->data->prompt_data == NULL)
	{
		printf("wtf\n\n");
		return(return_error(msh, NULL,"syntax error multiligne."));
	}
	printf("___2\n");
	ft_size_data(msh, buf);
	printf("___3\n");
	return (SUCCESS);
}
