/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:16:18 by loamar            #+#    #+#             */
/*   Updated: 2020/12/06 05:22:13 by loamar           ###   ########.fr       */
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
# define SQUOTE 39
# define DQUOTE 34
// data -> commands table

typedef struct		s_data
{
	char	**prompt_data;
	int 	*value_data;
	int 	count_data;
}					t_data;

typedef struct		s_split_data
{
	int 	nb;
	int 	index;
	int 	pos;
	int 	check;
	int 	word;

}					t_split_data;


# endif
