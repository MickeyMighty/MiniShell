/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:48:58 by loamar            #+#    #+#             */
/*   Updated: 2021/03/30 22:24:16 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

char			**ft_split_data(t_msh *msh, char *s, char c)
{
	char			**res;
	t_split_data	*split_data;

	split_data = init_split_data(split_data, s);
	if (split_data == NULL)
		return (NULL);
	if (check_word(split_data, s, c) == 0)
		ft_count_word(msh, s, c, split_data);
	else
		return (NULL);
	if (split_data->error == 1)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (split_data->nb_word + 1))))
		return (NULL);
	split_data->pos = 0;
	res = ft_word_to_tab(msh, s, split_data, res);
	if (res == NULL)
	{
		global_error_msg = 1;
		free(res);
		free(split_data);
		return (NULL);
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
	global_error_msg = 0;
	msh->data->size_data = 0;
	msh->data->prompt_data = ft_split_data(msh, buf, ' ');
	if (msh->data->prompt_data == NULL)
	{
		if (global_error_msg == 0)
			return (ERROR);
		else if (global_error_msg == 1)
			return (return_error(msh, NULL, NULL, "syntax error multiligne."));
	}
	ft_memset(buf, 0, ft_strlen(buf));
	free(buf);
	msh->data->size_data = global_size_word;
	return (SUCCESS);
}
