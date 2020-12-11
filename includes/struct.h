/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 02:31:14 by loamar            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/12/11 03:39:05 by loamar           ###   ########.fr       */
=======
/*   Updated: 2020/12/11 03:56:02 by tidminta         ###   ########.fr       */
>>>>>>> 1577a933a739790afc0ff6c3cfe0c5abc9e3cbbd
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct 		s_msh
{
	struct s_utils *utils;
	struct s_data 	*data;
	struct s_list 	*list;
	struct s_lair_list *lair_list;
}					t_msh;

typedef struct		s_utils
{
	int 	check_opt;
	int 	check_arg;
<<<<<<< HEAD
	int 	error_multi_line;
=======
	char	**separator_tab;
>>>>>>> 1577a933a739790afc0ff6c3cfe0c5abc9e3cbbd
}					t_utils;

typedef struct		s_data
{
	char	**prompt_data;
	// char 	lair_tab;
	int 	size_data;
	int 	check;
}					t_data;

typedef struct		s_list
{
	char			*content;
	int 			token;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

typedef struct 		s_lair_list
{
	t_list	*start;
	t_list	*end;
  	int size;
}					t_lair_list;



typedef struct		s_split_data
{
	int 	nb;
	int 	index;
	int 	pos;
	int 	check;
	int 	word;

}					t_split_data;

# endif
