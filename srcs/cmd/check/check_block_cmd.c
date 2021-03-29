/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_block_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 09:50:00 by loamar            #+#    #+#             */
/*   Updated: 2021/03/29 15:35:11 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

int			check_end(char *str, int pos)
{
	if (str[pos] != '\0' && (ft_isalnum(str[pos]) == 0))
		return (1);
	else
		return (0);
}

int			check_no_space(t_msh *msh, char *str)
{
	int index;

	index = msh->utils->pos;
	index--;
	if (index == 0)
		return (0);
	if (index > 0)
	{
		if (str[index - 1] == ' ')
			return (1);
		else if (str[index - 1] != '$' && str[index - 1] != ' ')
			return (0);
	}
	return (0);
}

char		*check_content(t_msh *msh, char *str)
{
	char	*first_step;
	char	*second_step;
	int		pos;

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

int			data_check(t_msh *msh)
{
	int		count;
	int		pos;

	count = 0;
	while (count < msh->data->size_data)
	{
		pos = 0;
		if (msh->data->prompt_data[count][pos] == '\'')
		{
			pos = data_check_qte(msh, count, pos, 0);
			if (pos == -1)
				return (-1);
		}
		else if (msh->data->prompt_data[count][pos] == '\"')
		{
			pos = data_check_qte(msh, count, pos, 1);
			if (pos == -1)
				return (-1);
		}
		count++;
	}
	return (1);
}

t_list		*check_block_cmd(t_msh *msh, t_list *element)
{
	int		pos;

	pos = 1;
	if (!element->content)
		return (NULL);
	msh->utils->no_space = 0;
	element->content = return_all_content(msh, element->content);
	if (element->content == NULL)
	{
		global_error_msg = ERROR_MULTI;
		return (NULL);
	}
	while (element->tab_args[pos] != NULL)
	{
		// if (msh->utils->no_space != 4)
		// 	msh->utils->no_space = 0;
		element->tab_args[pos] =
			return_all_content(msh, element->tab_args[pos]);
		if (element->tab_args[pos] == NULL)
		{
			global_error_msg = ERROR_MULTI;
			return (NULL);
		}
		pos++;
	}
	return (element);
}
