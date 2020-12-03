/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:35:59 by loamar            #+#    #+#             */
/*   Updated: 2020/12/03 17:04:43 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSHELL_H
# define LIBSHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>

# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include "./includes/tree_struct.h"
# include "./includes/data_struct.h"

// init

void 	init_shell(void);

// DATA

int 	sort_data(char *buf);
int 	check_data_separator(t_data *data);

char			**ft_split_data(char *s, char c);
int				ft_count_separator(char const *s, int pos);
int 	ft_count_word_noquote(char const *s, char c, int i, int nb);
int 	ft_count_word_quote(char const *s, char c, int i, int nb);

# endif
