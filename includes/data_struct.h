/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:16:18 by loamar            #+#    #+#             */
/*   Updated: 2020/12/11 01:55:54 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

# define PIPE 1
# define SEMICOLON 2
# define CHEVRONL 3
# define CHEVRONR 4
# define CHEVROND 5
# define AND 6
# define OR 7
# define VARIABLE 8
# define CMD 9
# define OPTION 10
# define ARG 11
# define SQUOTE 39
# define DQUOTE 34
// data -> commands table

typedef struct 		s_msh
{
		struct s_data 	*data;
		struct s_list 	*list;
		struct s_lair_list *lair_list;
		struct s_utils *utils;
}					t_msh;

t_msh 	*init_shell(t_msh *msh);

typedef struct		s_data
{
	char	**prompt_data;
	// char 	lair_tab;
	int 	size_data;
	int 	check;
}					t_data;

typedef struct		s_utils
{
	int 	check_opt;
	int 	check_arg;
}					t_utils;

typedef struct		s_prompt_list
{
	char			*content;
	int 			token;
	struct s_prompt_list	*next;
	struct s_prompt_list	*previous;
}					t_prompt_list;

typedef struct 		s_lair_list
{
	t_prompt_list	*start;
	t_prompt_list	*end;
  	int size;
}					t_lair_list;

int 	handler_data(t_msh *msh, char *buf);
int 	handler_list(t_msh *msh);
int 	ft_fill_empty_list(t_lair_list *lair_list, char *content);
int 	ft_fill_end_list(t_lair_list *lair_list, char *content);
int 	check_data_separator(t_data *data);
int 	check_prompt(t_data *data);
t_lair_list 	*init_data_lair_list(t_lair_list *lair_list);

typedef struct		s_split_data
{
	int 	nb;
	int 	index;
	int 	pos;
	int 	check;
	int 	word;

}					t_split_data;

char			**ft_split_data(char *s, char c);
int				ft_count_separator(char *s, int pos);
void 	ft_count_word_noquote(char *s, char c, t_split_data *data);
void 	ft_count_word_quote(char *s, char c, t_split_data *data);
int 	ft_get_len_word_quote(char *s, char c, t_split_data *data, int index);
void 	check_quote(char *s, t_split_data *data);

# endif
