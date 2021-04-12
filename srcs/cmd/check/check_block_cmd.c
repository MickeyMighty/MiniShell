/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_block_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 09:50:00 by loamar            #+#    #+#             */
/*   Updated: 2021/04/12 22:55:27 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

int				check_no_space(t_msh *msh, char *str)
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

int		put_pos_check(t_msh *msh, char *str, int start, int flag)
{
	int	pos;

	pos = start;
	if (flag == 1)
	{
		while (str[pos] == ' ')
		{
			if ((msh->utils->no_space == 1 || msh->utils->no_space == 3)
			&& str[pos + 1] != ' ')
				return (pos);
			pos++;
		}
		return (pos);
	}
	else if (flag == 2)
	{
		if (msh->utils->no_space == 2 || msh->utils->no_space == 3)
			return (pos);
		pos++;
		return (pos);
	}
	else
		return (pos);
}

char			*check_content(t_msh *msh, char *str, int key)
{
	char	*first_step;
	char	*second_step;
	int		pos;

	pos = 0;
	msh->utils->loop3 = 0;
	first_step = NULL;
	if (key == NOQTE)
		pos = put_pos_check(msh, str, pos, 1);
	while (str[pos] != '\0')
	{
		second_step = NULL;
		if (key == NOQTE)
			pos = return_pos(msh, str, pos);
		if (str[pos] == '\\' && str[pos + 1] == '\\')
			pos++;
		second_step = ft_substr(str, pos, 1);
		first_step = ft_free_strjoin(first_step, second_step, 1, 1);
		// first_step = join_and_free_first_step(msh, first_step, second_step, 3);
		if (str[pos])
			pos++;
	}
	return (first_step);
}

int				data_check(t_msh *msh)
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

t_list			*check_block_cmd(t_msh *msh, t_list *element)
{
	msh->utils = init_utils(msh->utils);
	if (!element->content)
		return (NULL);
	msh->utils->no_space = 0;
	if (ft_strcmp(element->content, "export") == 0)
		msh->utils->export_check = 1;
	element->content = return_all_content(msh, element->content);
	if (element->content == NULL)
	{
		g_error_msg = ERROR_MULTI;
		return (NULL);
	}
	while (element->tab_args[msh->utils->pos_args] != NULL)
	{
		msh->utils->no_space = 0;
		element->tab_args[msh->utils->pos_args] =
		return_all_content(msh, element->tab_args[msh->utils->pos_args]);
		if (element->tab_args[msh->utils->pos_args] == NULL)
		{
			g_error_msg = ERROR_MULTI;
			return (NULL);
		}
		msh->utils->pos_args++;
	}
	return (element);
}
