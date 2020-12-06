/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:16:18 by loamar            #+#    #+#             */
/*   Updated: 2020/12/06 07:25:00 by loamar           ###   ########.fr       */
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

typedef struct		s_list
{
	char			*content;
	int 			value;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

typedef struct 		s_lair_list
{
	struct s_list	*start;
	struct s_list	*end;
  	int size;
}					t_lair_liste;

int 	sort_data(t_data *data, char *buf);
int 	handler_data(t_data *data);
int 	check_data_separator(t_data *data);

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
