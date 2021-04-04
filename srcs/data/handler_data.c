/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:48:58 by loamar            #+#    #+#             */
/*   Updated: 2021/04/04 11:11:01 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static	char	**split_error(t_msh *msh, t_split_data *split_data, int error,
int free_s)
{
	if (free_s == 1)
		free(split_data);
	if (error == ERROR_MALLOC)
		global_error_msg = ERROR_MALLOC;
	else if (error == SUCCESS)
		global_error_msg = ERROR;
	else if (error == ERROR_MULTI)
		global_error_msg = ERROR_MULTI;
	return (NULL);
}

char			**ft_split_data(t_msh *msh, char *s, char c)
{
	char			**res;
	t_split_data	*split_data;

	split_data = init_split_data(split_data, s);
	if (split_data == NULL)
		return(split_error(msh, split_data, SUCCESS, 0));
	if (check_word(split_data, s, c) == 0)
		ft_count_word(msh, s, c, split_data);
	else
		return(split_error(msh, split_data, SUCCESS, 1));
	if (split_data->error == 1)
		return(split_error(msh, split_data, ERROR_MULTI, 1));
	if (!(res = (char **)malloc(sizeof(char *) * (split_data->nb_word + 1))))
		return(split_error(msh, split_data, ERROR_MALLOC, 1));
	split_data->pos = 0;
	res = ft_word_to_tab(msh, s, split_data, res);
	if (res == NULL)
	{
		free(res);
		return(split_error(msh, split_data, ERROR_MULTI, 2));
	}
	free(split_data);
	return (res);
}

int				get_value_sep(char *str)
{
	if (ft_strcmp(str, "|") == 0)
		return (PIPE);
	else if (ft_strcmp(str, "<") == 0 || ft_strcmp(str, ">") == 0
			|| ft_strcmp(str, ">>") == 0)
		return (REDIR);
	else if (ft_strcmp(str, ";") == 0)
		return (SEMICOLON);
	else
		return (0);
}

int				handler_data(t_msh *msh, char *buf)
{
	msh->data->size_data = 0;
	msh->data->prompt_data = ft_split_data(msh, buf, ' ');
	if (msh->data->prompt_data == NULL)
	{
		if (global_error_msg == ERROR)
			return (ERROR);
		else if (global_error_msg == ERROR_MALLOC)
			return (return_error(ERROR_MSG, NULL, NULL, "error from malloc."));
		else if (global_error_msg == ERROR_MULTI)
			return (return_error(ERROR_MSG, NULL, NULL, "syntax error multiligne."));
	}
	ft_memset(buf, 0, ft_strlen(buf));
	free(buf);
	if (data_check(msh) == -1)
		return (return_error(ERROR_MSG, NULL, NULL, "syntax error multiligne."));
	return (SUCCESS);
}
