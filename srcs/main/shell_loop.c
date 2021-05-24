/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 21:51:36 by loamar            #+#    #+#             */
/*   Updated: 2021/05/05 17:54:53 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

char	*ft_strcat(char *dst, const char *src)
{
	int		i;
	int		j;

	i = ft_strlen(dst);
	j = 0;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*ft_strjoin_middle(char *s1, const char *s2, int div)
{
	char	*str;
	int		l;

	l = ft_strlen(s1) + 1;
	if (!s2)
	{
		str = ft_strdup(s1);
		free((void*)s1);
		return (str);
	}
	if (!(str = (char*)malloc(sizeof(char) * (l + 2))))
		return (NULL);
	ft_strlcpy(str, s1, div);
	str[div] = '\0';
	ft_strcat(str, s2);
	while (div < l)
	{
		str[div] = s1[div - 1];
		div++;
	}
	ft_strdel(&s1);
	str[div] = '\0';
	return (str);
}

// static char	*ft_strjoin_middle2(char *s1, const char *s2, int div)
// {
// 	char	*str;
// 	int		l;
// 	char	*tmp;
//
// 	if (!s2)
// 	{
// 		str = ft_strdup(s1);
// 		free((void*)s1);
// 		return (str);
// 	}
// 	l = ft_strlen(s1) + ft_strlen(s2);
// 	if (!(str = (char*)malloc(sizeof(char) * (l + 1))))
// 		return (NULL);
// 	ft_strlcpy(str, s1, div + 1);
// 	ft_strcat(str, s2);
// 	tmp = ft_substr(s1, div, ft_strlen(s1) - div);
// 	ft_strcat(str, tmp);
// 	free(tmp);
// 	return (str);
// }

static int		putchar_tc(int tc)
{
	write(1, &tc, 1);
	return (0);
}

static void	fill_line(t_msh *msh, long c)
{
	char	c2[2];

	c2[0] = c;
	c2[1] = '\0';
	if (msh->termcap->line)
		msh->termcap->line = ft_strjoin_middle(msh->termcap->line, c2,
			msh->termcap->cur_pos + 1);
	else
		msh->termcap->line = ft_strdup(c2);
	msh->termcap->cur_pos++;
}

void 	shell_loop(t_msh *msh, char **env)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		// handler_termcap(msh, line);
		g_return(SET, SUCCESS);
		g_error(SET, SUCCESS);
		signal(SIGINT, handler_signal);
		msh = init_msh(msh);
		main_handler(msh, line, env);
		end_loop(msh, ENDLOOP);
		prompt();
	}
	free_all(msh, CTRLD);
	exit(0);
}

static void	cursor_win(t_msh *msh)
{
	struct winsize w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	msh->termcap->col = w.ws_col;
	msh->termcap->row = w.ws_row;
}

char		*g_cm(int mode, char *value)
{
	static char		*cm_value;

	if (mode == 1)
		cm_value = value;
	return (cm_value);
}

static void		handler_line2(t_msh *msh, long c)
{
	if ((msh->termcap->cur_pos + msh->termcap->plen + msh->termcap->start_col) % msh->termcap->col == 0 ||
		((msh->termcap->start_col + msh->termcap->cur_pos + msh->termcap->plen + 1) % msh->termcap->col == 0 &&
		c == BACKSPACE && msh->termcap->backspace != BACKSPACE) || ((msh->termcap->cur_pos +
		msh->termcap->plen + msh->termcap->start_col - 1) % msh->termcap->col == 0 && c != BACKSPACE &&
		msh->termcap->backspace == BACKSPACE))
	{
		c != BACKSPACE ? msh->termcap->mod_offset -= 1 : 0;
		c == BACKSPACE ? msh->termcap->mod_offset += 1 : 0;
		if (msh->termcap->currow >= msh->termcap->row)
		{
			msh->termcap->start_row -= 1;
			write(1, "\n", 1);
		}
	}
	msh->termcap->backspace = c;
	if ((msh->termcap->len + msh->termcap->plen + msh->termcap->start_col) % msh->termcap->col == 0
		&& c == BACKSPACE)
		write(1, " ", 1);
	tputs(tgoto(g_cm(GET, 0), (msh->termcap->start_col + msh->termcap->cur_pos + msh->termcap->plen)
		% msh->termcap->col, msh->termcap->currow - msh->termcap->mod_offset), 1, putchar_tc);
	// exit(0);
}

static void		handler_line(t_msh *msh, long c)
{
	tputs(tgoto(g_cm(GET, 0), msh->termcap->start_col, msh->termcap->currow), 1, putchar_tc);
	// tputs(msh->termcap->ce, 1, putchar_tc);
	// prompt();
	// if (msh->termcap->line && c != BACKSPACE)
	// printf("line = [%s]\n", msh->termcap->line);
	if (msh->termcap->line && c != BACKSPACE)
		ft_putchar_fd(c, 1);
	get_cursor_pos(msh, &msh->termcap->end_col, &msh->termcap->end_row);

	tputs(tgoto(g_cm(GET, 0), (msh->termcap->start_col), (msh->termcap->end_row)), 1, putchar_tc);
	// tputs(tgoto(g_cm(GET, 0), 1, 1, 1, putchar_tc);
	// tputs(msh->termcap->ce, 1, putchar_tc);
	// handler_line2(msh, c);
}

static void		handle_keys(t_msh *msh, long c)
{
	get_cursor_pos(msh, &msh->termcap->col, &msh->termcap->row);
	if (ft_isprint(c) == 1)
		fill_line(msh, c);
	// else if (c == BACKSPACE)
	else if (c == BACKSPACE && msh->termcap->cur_pos > 0)
		delete_char(msh);
	// else if (c == UP_ARROW)
	// 	up_history();
	// else if (c == DOWN_ARROW)
	// 	down_history();
	msh->termcap->len = 0;
	if (msh->termcap->line)
		msh->termcap->len = ft_strlen(msh->termcap->line);
	else
		msh->termcap->len = 0;
	handler_line(msh, c);
}

static	int 	termcap_loop(t_msh *msh)
{
	int		ret;
	long	c;

	c = 0;
	// printf("line = [%s]\n", msh->termcap->line);
	// g_cm(SET, tgetstr("cm", NULL));
	while ((ret = read(0, &c, sizeof(c))) > 0)
	{
		// printf("1 line = [%s]\n", msh->termcap->line);
		if (c == '\n')
		{
			if (msh->termcap->line == NULL || !msh->termcap->line)
				get_cursor_pos(msh, &msh->termcap->end_col, &msh->termcap->end_row);
			break ;
		}
		if ((c == EOF_KEY && msh->termcap->line == NULL && (ret = -1) == -1))
			exit_cmd(msh);
		// printf("2 line = [%s]\n", msh->termcap->line);
		handle_keys(msh, c);
		// printf("3 line = [%s]\n", msh->termcap->line);
		c = 0;
	}
	tputs(tgoto(g_cm(GET, 0), msh->termcap->end_col, msh->termcap->end_row), 1, putchar_tc);
	ft_putstr_fd("\n", 1);
	return (1);
}

void 	shell_loop_termcap(t_msh *msh, char **env)
{
	// g_cm(GET, 0) = tgetstr("cm")
	while (1)
	{
		signal(SIGINT, handler_signal);
		signal(SIGQUIT, handler_signal);
		g_return(SET, SUCCESS);
		g_error(SET, SUCCESS);
		msh = init_msh(msh);
		if (g_loop(GET, 0) == LOOP)
			init_term(msh);
		msh->termcap->mod_offset = 0;
		msh->termcap->cur_pos = 0;
		// msh->termcap->line = NULL;
		prompt();
		// get_cursor_pos(msh, &msh->termcap->start_col, &msh->termcap->start_row);
		// get_cursor_pos(msh, &msh->termcap->col, &msh->termcap->start_row);
		if (termcap_loop(msh))
		{
			printf("line = [%s]\n", msh->termcap->line);
			tcsetattr(0, TCSANOW, &msh->termcap->save);
			(void)env;
			if (g_cm(GET, 0))
				free(g_cm(GET, 0));
			tcsetattr(0, TCSANOW, &msh->termcap->save);
			handler_history(msh, msh->termcap->line);
			main_handler(msh, msh->termcap->line, env);
			end_loop(msh, ENDLOOP);
		}
		// handler_termcap(msh, line);
	}
}
