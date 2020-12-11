/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:35:59 by loamar            #+#    #+#             */
/*   Updated: 2020/12/11 06:03:00 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSHELL_H
# define LIBSHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <signal.h>
# include <sys/types.h>

# include "./includes/struct.h"
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include "./includes/list.h"
# include "./includes/data.h"
# include "./includes/cmd.h"

t_msh 	*init_shell(t_msh *msh);
int 	data_check(t_msh *msh);
void 	free_error(t_msh *msh);
int 	handler_error(t_msh *msh);


# endif
