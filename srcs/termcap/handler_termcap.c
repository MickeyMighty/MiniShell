/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_termcap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 02:39:00 by loamar            #+#    #+#             */
/*   Updated: 2021/04/27 19:01:09 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

//isatty, ttyname, ttyslot, ioctl,
//getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
//tgetnum, tgetstr, tgoto, tputs

static	int	init_term(char *line)
{
	int		ret;
	char	*term_type;

	ret = 0;
	term_type = NULL;
	term_type = getenv("TERM");
	(void)line;
	if (term_type == NULL)
		return (return_error(ERROR_MSG, NULL, NULL, "TERM must be set (see 'env')"));
	ret = tgetent(NULL, term_type);
	if (ret == -1)
		return (return_error(ERROR_MSG, NULL, NULL, "Could not access to the termcap database"));
	if (ret == 0)
		return (return_error(ERROR_MSG, NULL, NULL, "Terminal type '%s' is not defined in termcap database (or have too few informations)"));
	return (ret);
}

int		handler_termcap(t_msh *msh, char *line)
{
	int		ret;
	struct	termios	term;

	tcgeattr(0, &term);
	// ret = init_term(NULL, STDOUT_FILENO, NULL);
	ret = init_term(line);
	if (g_loop(GET, 0) == LOOP)
	{
		msh->term_lair = init_term_lair(msh->term_lair);
		if (msh->term_lair == NULL)
			return (ERROR);
		msh->term_list = NULL;
	}
	if (msh->term_lair->size == 0)
		ft_fill_empty_term(msh->term_lair, line);
	else
		ft_fill_start_term(msh->term_lair, line);
	return (0);
}
