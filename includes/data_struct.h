/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:16:18 by loamar            #+#    #+#             */
/*   Updated: 2020/12/08 17:07:48 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

# define PIPE 0
# define SEMICOLON 1
# define CHEVRONL 2
# define CHEVRONR 3
# define CHEVROND 4
# define AND 5
# define OR 6
# define VARIABLE 7
# define SQ 8
# define DQ 9
# define CMD 10
# define OPTION 12
# define SQUOTE 39
# define DQUOTE 34
// data -> commands table

typedef struct		s_data
{
	char	**prompt_data;
	char 	**lair_tab;
	int 	*value_data;
	int 	size_data;
	int 	check;
}					t_data;

typedef struct		s_prompt_list
{
	char			*content;
	int 			value;
	struct s_prompt_list	*next;
	struct s_prompt_list	*previous;
}					t_prompt_list;

typedef struct 		s_lair_list
{
	t_prompt_list	*start;
	t_prompt_list	*end;
  	int size;
}					t_lair_list;

int 	sort_data(t_data *data, char *buf);
int 	handler_data(t_data *data, t_prompt_list *prompt_list, t_lair_list *lair_list);
t_prompt_list 	*ft_fill_empty_list(t_lair_list *lair_list, char *content);
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
