/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:35:59 by loamar            #+#    #+#             */
/*   Updated: 2020/12/06 07:08:19 by loamar           ###   ########.fr       */
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


# endif
