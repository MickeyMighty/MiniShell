/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:48:58 by loamar            #+#    #+#             */
/*   Updated: 2021/04/22 22:48:03 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static	char	**split_error(t_split_data *split_data, int error, int free_s)
{
	if (free_s == 1)
		free(split_data);
	if (error == ERROR_DBLSEMICOLON)
		g_error_msg(SET, ERROR_DBLSEMICOLON);
	else if (error == ERROR_MALLOC)
		g_error_msg(SET, ERROR_MALLOC);
	else if (error == SUCCESS)
		g_error_msg(SET, ERROR);
	else if (error == ERROR_MULTI)
		g_error_msg(SET, ERROR_MULTI);
	return (NULL);
}

static	int		check_and_count_word(t_msh *msh, char *s, char c,
t_split_data *split_data)
{
	if (check_word(s, c) == 0)
		ft_count_word(msh, s, c, split_data);
	else
	{
		split_error(split_data, SUCCESS, 1);
		return (ERROR);
	}
	if (split_data->error == 1)
	{
		split_error(split_data, ERROR_MULTI, 1);
		return (ERROR);
	}
	if (split_data->error == 2)
	{
		split_error(split_data, ERROR_DBLSEMICOLON, 1);
		return (ERROR);
	}
	return (SUCCESS);
}

char			**ft_split_data(t_msh *msh, char *s, char c)
{
	char			**res;
	t_split_data	*split_data;

	split_data = NULL;
	if (!s || s[0] == '\0' || s == NULL)
		return (split_error(split_data, SUCCESS, 0));
	split_data = init_split_data(split_data);
	if (split_data == NULL)
		return (split_error(split_data, SUCCESS, 1));
	if (check_and_count_word(msh, s, c, split_data) == ERROR)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (split_data->nb_word))))
		return (split_error(split_data, ERROR_MALLOC, 1));
	split_data->pos = 0;
	res = ft_word_to_tab(s, split_data, res);
	if (res == NULL)
	{
		free(res);
		return (split_error(split_data, ERROR_MULTI, 1));
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
		if (g_error_msg(GET, 0) == ERROR)
			return (ERROR);
		else if (g_error_msg(GET, 0) == ERROR_DBLSEMICOLON)
			return (return_error(ERROR_TOKEN, ";;", NULL,
			"syntax error near unexpected token"));
		else if (g_error_msg(GET, 0) == ERROR_MALLOC)
			return (return_error(ERROR_MSG, NULL, NULL, "error from malloc"));
		else if (g_error_msg(GET, 0) == ERROR_MULTI)
			return (return_error(ERROR_MSG, NULL, NULL,
				"syntax error multiligne"));
	}
	ft_memset(buf, 0, ft_strlen(buf));
	free(buf);
	if (data_check(msh) == -1)
	{
		return (return_error(ERROR_MSG, NULL, NULL,
		"syntax error multiligne."));
	}
	return (SUCCESS);
}
