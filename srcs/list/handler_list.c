/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 04:42:10 by loamar            #+#    #+#             */
/*   Updated: 2021/04/19 15:48:41 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static	int		error_pipe_multi(t_list *element)
{
	if (element->next && element->token == SEPARATOR
	&& element->next->token == SEPARATOR
	&& get_value_sep(element->content) == PIPE
	&& get_value_sep(element->next->content) == PIPE
	&& (element->next->next == NULL || !element->next->next))
	{
		return (return_error(ERROR_MULTI, NULL, NULL,
		"syntax error multiligne"));
	}
	if ((!element->next || (element->next == NULL))
	&& (element->token == SEPARATOR)
	&& (get_value_sep(element->content) == PIPE))
	{
		return (return_error(ERROR_MULTI, NULL, NULL,
		"syntax error multiligne"));
	}
	return (SUCCESS);
}

int		check_pipe_multi(t_msh *msh)
{
	t_list		*element;
	int			ret;

	ret = 0;
	element = msh->lair_list->start;
	if (!element || (element == NULL))
		return (ERROR);
	while (element)
	{
		if (element->token == CMD && element->next)
		{
			element = element->next;
			ret = error_pipe_multi(element);
			if (ret == ERROR)
				return (ret);
		}
		else
			element = element->next;
	}
	return (SUCCESS);
}

static	int		check_cmd_list(t_list *element, int size)
{
	if (size > 1)
		if (element->previous->token == SEPARATOR)
			element = element->previous;
	return (error_cmd(element));
}

int				check_token_list(t_msh *msh)
{
	t_list		*element;
	int			check_cmd;
	int			size;

	size = 1;
	check_cmd = 0;
	element = msh->lair_list->start;
	if (!element || (element == NULL))
		return (ERROR);
	if (element->token == SEPARATOR)
		return (check_cmd_list(element, size));
	while (element)
	{
		if (element->token == CMD)
			check_cmd = 1;
		else if (element->token == SEPARATOR)
		{
			if (check_cmd == 0)
				return (check_cmd_list(element, size));
			check_cmd = 0;
		}
		size++;
		element = element->next;
	}
	return (SUCCESS);
}

int				handler_list(t_msh *msh)
{
	int		count;

	count = 0;
	msh->lair_list = init_lair_list(msh->lair_list);
	if (msh->lair_list == NULL)
		return (ERROR);
	if (msh->data->prompt_data[count] != NULL)
		ft_fill_empty_list(msh->lair_list, msh->data->prompt_data[count]);
	else
		return (SUCCESS);
	count++;
	while (count < msh->data->size_data)
	{
		ft_fill_end_list(msh->lair_list, msh->data->prompt_data[count]);
		count++;
	}
	free(msh->data->prompt_data);
	if (check_handler_list(msh) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
