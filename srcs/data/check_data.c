/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:13:10 by loamar            #+#    #+#             */
/*   Updated: 2020/12/03 16:33:54 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int 	check_data_separator(t_data *data, int pos)
{
	if (data->prompt_data[pos1][0] == "|")
		data->value_data[pos1][0] = PIPE;
	else if (data->prompt_data[pos1][0] == ";")
		data->value_data[pos1][0] = SEMICOLON;
	else if (data->prompt_data[pos1][0] == "<")
		data->value_data[pos1][0] = CHEVRONL;
	else if (data->prompt_data[pos1][0] == ">")
		data->value_data[pos1][0] = CHEVRONR;
	else if (data->prompt_data[pos1][0] == ">>")
		data->value_data[pos1][0] = CHEVROND;
	else if (data->prompt_data[pos1][0] == "&")
		data->value_data[pos1][0] = AND;
	else if (data->prompt_data[pos1][0] == "||")
		data->value_data[pos] = OR;
	else
		data->value_data[pos] == CMD;
	return (1);
}

int 	check_data_separator(t_data *data)
{
	int 	pos;

	pos = 0;
	data->value_data = (int*)malloc(sizeof(int) * data->count_data);
	if (data->value_data == NULL)
	return (0);
	while (pos <= data->count_data)
	{
		check_data_separator(data, pos);
		pos++;
	}
	return (1);
}
// int 	check_data_separator(t_data *data, int pos)
//
// 	else if (data->prompt_data[pos] == "")
// 	data->value_data[pos] = ;
// 	else if (data->prompt_data[pos] == "<")
// 	data->value_data[pos] = CHEVRONL;
// 	else if (data->prompt_data[pos] == ">")
// 	data->value_data[pos] = CHEVRONR;
// 	else if (data->prompt_data[pos] == ">>")
// }






//static int 		check_separator_data(char)

static int 		check_echo_data(char str)
{
	int 	pos;

	pos = 0;
	if ((str[pos] == 'e' || str[pos] == 'E')
	&& (str[pos + 1] == 'c' || str[pos + 1] == 'C')
	&& (str[pos + 2] == 'h' || str[pos + 2] == 'H')
	&& (str[pos + 3] == 'o' || str[pos + 3] == 'O'))
		return (1);
	else
		return (0);

}

int 	check_block_data(t_data *data)
{
	int 	check;

	check = 0;
	while (check_echo_data(data->prompt_data(check)))
}
