/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:05:04 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/09 13:05:45 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stdarg.h>

typedef struct	s_strlist
{
	void				*data;
	int					argpos;
	int					is_arg;
	char				argtype;
	struct s_strlist	*next;

}				t_strlist;

int				numberhandler(void *number, char type);
int				myprinter(const char *str, int start, int end);
int				findarg(const char *format, va_list ap);
int				parser(const char *format, va_list ap);
char			*ft_itoa_base(long number, int base);

void			listadd(t_strlist **mainlist, t_strlist *newelem);
t_strlist		*newlistelem(char const *inputstr, int start, int end);
t_strlist		*ft_add_elem(void *data);
int				b_printf(const char *format, ...);
int				is_vartype(char c);
void			oldlistadd(t_strlist **mainlist, const char *newstr);
char			*cutstr(char const *inputstr, int start, int end);
char			*ft_newstr(size_t size);
int				countdigits(long number, int base);
int				myatoi_base(const char *str, int str_base);
void			printhex(unsigned int x);

void			ft_putnbr(int nb);
void			ft_putstr(char *str);
void			ft_putchar(char c);
int				ft_atoi(char *str);

char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
int				ft_isdigit(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memset(void *b, int c, size_t len);

#endif
