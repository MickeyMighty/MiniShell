/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:16:18 by loamar            #+#    #+#             */
/*   Updated: 2020/11/13 15:36:34 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

# define PIPE 2
# define SEMICOLON 3
# define CHEVRONL 4
# define CHEVRONR 5
# define CHEVROND 6
# define AND 7
# define OR 8
# define CMD 9
# define VARIABLE 10
# define OPTION 11
// data -> commands table

typedef struct		s_data
{
	char	**prompt_data;
	int 	*value_data;
	int 	count_data;
}					t_data;

# endif
