/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:35:59 by loamar            #+#    #+#             */
/*   Updated: 2020/11/13 15:40:32 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSHELL_H
# define LIBSHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include "./includes/tree_struct.h"
# include "./includes/data_struct.h"

// init

void 	init_shell(void);

// DATA

int 	sort_data(char *buf);
int 	check_data_separator(t_data *data)

# endif
