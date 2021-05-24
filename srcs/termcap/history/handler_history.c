/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 02:39:00 by loamar            #+#    #+#             */
/*   Updated: 2021/05/06 01:12:39 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libshell.h"

//isatty, ttyname, ttyslot, ioctl,
//getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
//tgetnum, tgetstr, tgoto, tputs

static void	init_tc(t_msh *msh)
{
	g_cm(GET, tgetstr("cm", NULL));
	msh->termcap->ce = tgetstr("ce", NULL);
	msh->termcap->dl = tgetstr("DL", NULL);
}

void	init_term(t_msh *msh)
{
	char	*term_type;

	term_type = NULL;
	if (!(term_type = getenv("TERM")))
		term_type = "xterm";
	tgetent(NULL, term_type);
	setupterm(NULL, STDOUT_FILENO, NULL);
	tcgetattr(0, &msh->termcap->term);
	tcgetattr(0, &msh->termcap->save);
	msh->termcap->term.c_lflag = msh->termcap->term.c_lflag & ~ICANON;
	msh->termcap->term.c_lflag = msh->termcap->term.c_lflag & ~ECHO;
	msh->termcap->term.c_cc[VMIN] = 1;
	msh->termcap->term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &msh->termcap->term);
	init_tc(msh);
}

static size_t		ft_intlen(intmax_t n)
{
	size_t		len;

	len = 0;
	if (!n)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	get_cursor_pos(t_msh *msh, int *col, int *rows)
{
	int		a;
	int		pos;
	char	buf[255];
	int		ret;

	a = 0;
	pos = 1;
	write(0, "\033[6n", 4);
	ret = read(0, buf, 254);
	buf[ret] = '\0';
	while (buf[pos])
	{
		if (buf[pos] >= 48 && buf[pos] <= 57)
		{
			if (a == 0)
				*rows = ft_atoi(&buf[pos]) - 1;
			else
				*col = ft_atoi(&buf[pos]) - 1;

			a++;
			pos += ft_intlen(msh->termcap->col) - 1;
		}
		pos++;
	}
}

int		handler_history(t_msh *msh, char *line)
{
	if (g_loop(GET, 0) == LOOP || !msh->history_lair)
	{
		msh->history_lair = init_history_lair(msh->history_lair);
		if (msh->history_lair == NULL)
			return (ERROR);
		msh->history_list = NULL;
	}
	if (msh->history_lair->size == 0)
		ft_fill_empty_history(msh->history_lair, line);
	else
		ft_fill_start_history(msh->history_lair, line);
	return (0);
}
