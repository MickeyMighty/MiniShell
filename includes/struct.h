/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:09:50 by loamar            #+#    #+#             */
/*   Updated: 2021/03/21 22:41:02 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCT_H
# define STRUCT_H

typedef struct 		s_msh
{
	struct s_utils 		*utils;
	struct s_data 		*data;
	struct s_list 		*list;
	struct s_lair_list 	*lair_list;
	struct s_env_list 	*env_list;
	struct s_env_lair 	*env_lair;
}					t_msh;

typedef struct		s_utils
{
	int 	size_opt_arg;
	int 	status;
	int 	check;
	int 	pos;
	char 	quote;
	int 	no_space;
	// int 	check_opt; // ?
	// int 	check_arg; // ?
	// int 	check_sep; // ?
	int 	len;
	int 	pos_list;
	int 	multi_pipe;
	char 	*lair_export;
	char 	*tmp_utils;
	char 	**path;
	char	**sep_tab;
	// char 	**tab_args;
}					t_utils;

typedef struct		s_split_data
{
	int 	nb_word;
	int 	nb;
	int 	pos;
	int 	pos_index;
	int 	size;
	int 	error;

}					t_split_data;

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
	char			**tab_args;
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

typedef struct		s_env_list
{
	char			*first_content;
	char			*second_content;
	struct s_env_list	*next;
	struct s_env_list	*previous;
}					t_env_list;

typedef struct 		s_env_lair
{
	t_env_list	*start;
	t_env_list	*end;
  	int size;
}					t_env_lair;

# endif
