/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:05:04 by jguleski          #+#    #+#             */
/*   Updated: 2018/09/27 23:24:33 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdarg.h>
# include <errno.h>

typedef struct	s_afile
{
	mode_t				permisii;
	char				*name;
	int					linksnum;	
	char				*user;
	char				*group;
	size_t				fsize;
	time_t				timemodified;	
	//char				*timestr;
	char				type;
	blkcnt_t			blocks;
	char				linkedfile[1024];
	struct s_afile		*next;

}				t_afile;

void			getslink(const char *path, t_afile *thefile);
size_t			blockcounter(t_afile *alist);
void			clearlist(t_afile *head);
void			rtimesort(t_afile **head, t_afile *element);
void			timesort(t_afile **head, t_afile *element);
size_t			sizechecker(t_afile *alist);
void			printpermisii(mode_t filemode);
char			*getfilepath(const char *folder, const char *filename);
void			timeprinter(t_afile *dfile);
void			blsprinter(t_afile *filelist, const char *flags);
char			flagchecker(const char *flags);
void			revabcsort(t_afile **head, t_afile *element);
void			abcsort(t_afile **head, t_afile *element);
void			blslist(t_afile **head, t_afile *element, const char *flags);
t_afile			*fillelem(const char *path, char const *fname);
void			b_ls(const char *flags, const char *folder);

int				numberhandler(void *number, char type);
int				myprinter(const char *str, int start, int end);
int				findarg(const char *format, va_list ap);
int				parser(const char *format, va_list ap);
char			*ft_itoa_base(long number, int base);

typedef struct	s_strlist
{
	void				*data;
	int					argpos;
	int					is_arg;
	char				argtype;
	struct s_strlist	*next;

}				t_strlist;

void			ft_memdel(void **ap);
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
