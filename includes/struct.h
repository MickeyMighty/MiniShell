/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:09:50 by loamar            #+#    #+#             */
/*   Updated: 2021/03/11 14:46:21 by loamar           ###   ########.fr       */
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
	pid_t 	pid; //?
	pid_t 	wpid; //?
	int 	size_opt_arg;
	int 	status;
	int 	check;
	int 	pos1;
	int 	pos2;
	int 	pos3;
	int 	check_opt; // ?
	int 	check_arg; // ?
	int 	check_sep; // ?
	int 	pos_list;
	int 	multi_pipe;
	char 	*tmp_utils;
	char 	**path;
	char	**sep_tab;
	// char 	**tab_args;
}					t_utils;

typedef struct		s_split_data
{
	int 	nb;
	int 	index;
	int 	pos;
	int 	check;
	int 	check2;
	int 	word;

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
	int 			dollar;
	int 			quote;
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
