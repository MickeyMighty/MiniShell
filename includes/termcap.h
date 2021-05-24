/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 12:23:54 by loamar            #+#    #+#             */
/*   Updated: 2021/04/29 14:14:24 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H

# include "libshell.h"
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <termcap.h>

# define BACKSPACE 127
# define EOF_KEY 4
# define LEFT_ARROW 4479771
# define RIGHT_ARROW 4414235
# define UP_ARROW 4283163
# define DOWN_ARROW 4348699

# define HOME 4741915
# define END 4610843

# define ALT_X 8948194
# define ALT_C 42947
# define ALT_V 10127586

# define CTRL_LEFT 74995417045787
# define CTRL_RIGHT 73895905418011
# define CTRL_UP 71696882162459
# define CTRL_DOWN 72796393790235
// typedef struct		s_termcap
// {
// 	struct termios	term;
// 	struct termios	term_backup;
// 	// t_hist			*history;
// 	// t_hist			*cur_history;
// 	// char			*backup_cmd;
// 	// char			*copy_cmd;
// 	int				start_row;
// 	int				start_col;
// 	int				col;
// 	int				row;
// 	int				plen;
// 	int				cur_pos;
// 	int				currow;
// 	int				curcol;
// 	int				lenlen;
// 	int				rowoffset;
// 	int				mod_offset;
// 	int				endcol;
// 	int				endrow;
// 	char			*cm;
// 	char			*ce;
// 	char			*dl;
// 	long			backspace;
// }					t_termcap;

// t_termcap			*g_tc;

# endif
