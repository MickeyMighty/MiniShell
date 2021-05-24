/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:24:04 by loamar            #+#    #+#             */
/*   Updated: 2021/05/01 12:52:10 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list_libft
{
	void			*content;
	struct s_list	*next;
}					t_list_libft;

typedef struct		s_num
{
	long			pos;
	long			len;
	long			tmp;
}					t_num;

char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_free_strjoin(char *s1, char *s2);
int					ft_strcmp(char *s1, char *s2);
void				ft_memdel(void **ap);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
char				*ft_newstr(size_t size);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_ltohex_spe(long num);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isprecision(int c);
int					ft_atoi(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_abs(int i);
int					ft_islower(int c);
int					ft_isupper(int c);
char				*ft_strtoupper(char *str);
size_t				ft_strlen(const char *str);
void				ft_strdel(char **as);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *src, const char *sub, size_t len);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_itoa(long int n);
char				**ft_split(char *s, char c);
char				*ft_stohex(char *str);
void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putnbr(int n);
void				ft_putzero(size_t n);
void				ft_putspace(size_t n);
void				ft_bzero(void *s, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_calloc(size_t count, size_t size);
unsigned long		ft_unsigned(long int n);
int					ft_lstsize(t_list_libft *lst);
int					ft_atoi_base(char *str, char *base);
void				ft_lstadd_front(t_list_libft **alst, t_list_libft *new);
void				ft_lstadd_back(t_list_libft **alst, t_list_libft *new);
void				ft_lstdelone(t_list_libft *lst, void (*del)(void *));
void				ft_lstclear(t_list_libft **lst, void (*del)(void *));
void				ft_lstiter(t_list_libft *lst, void (*f)(void *));
t_list_libft		*ft_lstnew(void *content);
t_list_libft		*ft_lstlast(t_list_libft *lst);
t_list_libft		*ft_lstmap(t_list_libft *lst, void *(*f)(void *),
					void (*d)(void *));
char				*ft_ltohex(long num);
#endif
