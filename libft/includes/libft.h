/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 23:52:42 by arkim             #+#    #+#             */
/*   Updated: 2020/01/24 22:43:23 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

# define STDIN		0
# define STDOUT		1
# define STDERR		2

# define BUFF_SIZE 4096
# define MAX_FD 4096

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					get_next_line(const int fd, char **line);

/*
**					extra functions
*/

unsigned int		ft_abs(int n);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
int					ft_iswspace3(char c);
int					ft_nbrlen(int n);
int					ft_nbrlen_base(int n, unsigned int base);
int					ft_wordlen(char const *s, char c);
int					ft_countword(char const *s, char c);
void				ft_swap(void *a, void *b, size_t n);
void				ft_strswap(char **s1, char **s2);
void				ft_puterror(char const *error_msg);
int					ft_isdigit_base(char c, int base);
int					ft_strchr_idx(const char *s, int c);
char				*ft_itoa_base(int n, unsigned int base);
char				*ft_strtolower(char *str);
char				*ft_strtoupper(char *str);
void				ft_nputchar(char c, int n);
void				ft_nputchar_fd(char c, int n, int fd);
int					ft_iselem(char c, char *str);
uint64_t			ft_pow(int n, unsigned int exp);
char				*ft_strappend(char const *s1, char const *s2, \
				int n1, int n2);
int					ft_readfd(int fd, char **file);

/*
**					string.h
*/

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle, \
				size_t len);

/*
**					stdlib.h
*/

int					ft_atoi(const char *str);

/*
**					ctype.h
*/

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isblank(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isascii(int c);
int					ft_isspace(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
**					libft functions
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
