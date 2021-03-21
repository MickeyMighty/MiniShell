/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_block_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 09:50:00 by loamar            #+#    #+#             */
/*   Updated: 2021/03/20 16:54:10 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

char 	*check_content(char *str)
{
	char 	*first_step;
	char 	*second_step;
	int 	pos;

	pos = 0;
	first_step = NULL;
	while (str[pos] != '\0')
	{
		second_step = NULL;
		if (str[pos] == '\\' && (pos + 1) <= ft_strlen(str))
			pos++;
		else
		{
			second_step = ft_substr(str, msh->utils->pos, 1);
			first_step = ft_strjoin(first_step, second_step);
			free(second_step);
		}
		pos++;
	}
	if (str)
		free(str);
	return (first_step);
}

int 	data_check(t_msh *msh)
{
	int 	count;
	int 	pos;

	count = 0;
	while (count < msh->data->size_data)
	{
		pos = 0;
		if (msh->data->prompt_data[count][pos] == '\'')
		{
			pos++;
			while (msh->data->prompt_data[count][pos] != '\'')
			{
				if (msh->data->prompt_data[count][pos] == '\0')
					return (-1);
				pos++;
			}
		}
		else if (msh->data->prompt_data[count][pos] == '\"')
		{
			pos++;
			while (msh->data->prompt_data[count][pos] != '\"')
			{
				if (msh->data->prompt_data[count][pos] == '\0')
					return (-1);
				pos++;
			}
		}
		count++;
	}
	return (1);
}

t_list			*check_block_cmd(t_msh *msh, t_list *element)
{
	int 	pos;

	pos = 1;
	if (!element->content)
		return (NULL);
	msh->utils->no_space = 0;
	element->content = return_all_content(msh, element->content);
	while (element->tab_args[pos] != NULL)
	{
		msh->utils->no_space = 0;
		element->tab_args[pos] = return_all_content(msh, element->tab_args[pos]);
		pos++;
	}
	msh->utils->pos = 0;
	return (element);
}
