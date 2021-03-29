/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:10:32 by loamar            #+#    #+#             */
/*   Updated: 2021/03/28 21:35:21 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int			get_quote(char *str)
{
	if (!str)
		return (0);
	else if (str[0] == '\'')
		return (1);
	else if (str[0] == '\"')
		return (2);
	else
		return (0);
}

static int	separator_check(t_msh *msh, char *s)
{
	if (!ft_strncmp(s, "|", ft_strlen(s))
		&& ft_strlen(s) == 1)
		return (1);
	else if (!ft_strncmp(s, ";", ft_strlen(s))
		&& ft_strlen(s) == 1)
		return (1);
	else if (!ft_strncmp(s, "<", ft_strlen(s))
		&& ft_strlen(s) == 1)
		return (1);
	else if (!ft_strncmp(s, ">", ft_strlen(s))
		&& ft_strlen(s) == 1)
		return (1);
	else if (!ft_strncmp(s, ">>", ft_strlen(s))
		&& ft_strlen(s) == 2)
		return (1);
	return (0);
}

static int	option_check(t_msh *msh, char *s)
{
	(void)msh;
	if (!s[0])
		return (0);
	if (s[0] == 45)
		return (OPTION);
	else if (s[1] && ((s[0] == DQUOTE && s[1] == 45)
	|| (s[0] == SQUOTE && s[1] == 45)))
		return (OPTION);
	else
		return (0);
}

static int	token_recognition(t_msh *msh, char *s, int indice)
{
	if (indice == 0)
	{
		if (separator_check(msh, s) == 1)
			return (SEPARATOR);
		else
			return (CMD);
	}
	else if (((indice == 1 && option_check(msh, s))
	|| (indice > 1 && option_check(msh, s)))
			&& (msh->utils->check_arg == 0))
		return (OPTION);
	else if (indice != 0 && separator_check(msh, s) == 1)
		return (SEPARATOR);
	else
	{
		msh->utils->check_arg = 1;
		return (ARGS);
	}
	return (0);
}

void		set_token_list(t_msh *msh)
{
	t_list	*lst;
	int		i;
	int		args;

	lst = msh->lair_list->start;
	i = 0;
	args = 0;
	while (lst != NULL)
	{
		lst->token = token_recognition(msh, lst->content, i);
		i++;
		i = (lst->token == SEPARATOR) ? 0 : i;
		lst = lst->next;
	}
}
