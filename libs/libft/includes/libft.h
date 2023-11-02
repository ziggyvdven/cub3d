/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:37:21 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/10/06 10:43:34 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <stdbool.h>

# define BUFFER_SIZE 100

typedef struct s_tokens	t_tokens;

typedef struct s_data
{
	char		*str;
	int			token_id;
}	t_data;

typedef struct s_tokens
{
	t_data		*data;
	t_tokens	*next;
}	t_tokens;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
bool		ft_iswspace(char c);
size_t		ft_strlen(const char *s);
int			ft_strlen_int(const char *s);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
int			ft_toupper(int c);
int			ft_tolower(int c);
bool		ft_hasalpha(char *s);
bool		ft_hasdigit(char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_atoi(const char *nptr);
long long	ft_atoll(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_free(char *s1, char *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putchar(char c);
void		ft_putstr_fd(char *s, int fd);
void		ft_putstr_exit(char *str, int fd, int exit_status);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_tokens	*ft_lstnew(t_data *data);
void		ft_lstadd_front(t_tokens **lst, t_tokens *new);
int			ft_lstsize(t_tokens *lst);
void		ft_lstclear(t_tokens **lst);
void		ft_clearlst(t_tokens **lst);
t_tokens	*ft_lstlast(t_tokens *lst);
t_tokens	*ft_lstadd_back(t_tokens *lst, t_tokens *new);
void		ft_lstdelone(t_tokens *lst);
void		ft_lstdelone2(t_tokens *lst);
// void		ft_lstclear(t_tokens **lst, void (*del)(int));
void		ft_lstiter(t_tokens *lst, void (*f)(void *));
void		ft_printlst(t_tokens *map_lst);
t_tokens	*ft_lstmap(t_tokens *lst, void *(*f)(int), void (*del)(int));
void		ft_putnbr_base(int nbr, char *base);
int			ft_strisdigit(char *str);
long int	ft_atol(const char *nptr);
void		ft_swap(int *a, int *b);
void		ft_free_ar(char **ar);
void		ft_free_n_ar(char **ar, int n);
void		ft_free_str(char *str);
void		ft_printmap(char **map);
int			ft_count_cuts(char *str, char c);

/*PRINTF*********************************/
int			ft_printf(const char *s, ...);
size_t		ft_strlen(const char *s);
void		ft_putchar(char c);
int			ft_putnbr_pf(int n, int count);
int			ft_putstr(char *str);
int			ft_putunsing(unsigned int n, int count);
int			ft_putnbr_base_pf(unsigned int nbr, int count, int b);
int			ft_printadr(va_list *args);

/*GNL*********************************/
char		*get_next_line(int fd);
char		*ft_make_line(char *s, char *nl);
char		*ft_stash(char *stash_ptr);
char		*ft_readline(char *s, int fd);
size_t		ft_strlen_gnl(const char *s);
void		*ft_calloc_gnl(size_t nmemb, size_t size);
char		*ft_strjoin_gnl(char *s1, char *s2, int r);
int			strchr_gnl(const char *s, int c);
int			ft_strlcpy_gnl(char *dst, char *src, int dstsize);
void		*calloc_gnl(size_t nmemb, size_t size);
char		*ft_free_gnl(char *s);

#endif
