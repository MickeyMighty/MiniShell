/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 12:47:53 by loamar            #+#    #+#             */
/*   Updated: 2021/05/02 00:38:15 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

void	delete_char(t_msh *msh)
{
	char	*str;
	int		len;

	if (!msh->termcap->line || msh->termcap->line == NULL)
		return ;
	len = ft_strlen(msh->termcap->line);
	if (len == 1 && msh->termcap->cur_pos == 1)
	{
		ft_strdel(&msh->termcap->line);
		msh->termcap->cur_pos--;
		return ;
	}
	if (!(str = (char*)ft_calloc(1, sizeof(char) * (len))))
		return ;
	ft_strlcpy(str, msh->termcap->line, msh->termcap->cur_pos);
	ft_strncat(str, msh->termcap->line + msh->termcap->cur_pos, len - msh->termcap->cur_pos);
	ft_strdel(&msh->termcap->line);
	msh->termcap->line = str;
	msh->termcap->cur_pos--;
}
