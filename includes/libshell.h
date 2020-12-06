/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:35:59 by loamar            #+#    #+#             */
/*   Updated: 2020/12/06 05:37:14 by loamar           ###   ########.fr       */
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

int 	sort_data(t_data *data, char *buf);
int 	handler_data(t_data *data);
int 	check_data_separator(t_data *data);

char			**ft_split_data(char *s, char c);
int				ft_count_separator(char *s, int pos);
void 	ft_count_word_noquote(char *s, char c, t_split_data *data);
void 	ft_count_word_quote(char *s, char c, t_split_data *data);
int 	ft_get_len_word_quote(char *s, char c, t_split_data *data, int index);
void 	check_quote(char *s, t_split_data *data);

# endif
