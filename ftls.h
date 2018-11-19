/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:05:04 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/19 15:31:43 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLS_H
# define FTLS_H

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
# include <sys/acl.h>
# include <sys/xattr.h>
# include "libft/includes/libft.h"

typedef struct	s_afile
{
	struct timespec		fnano;
	mode_t				permisii;
	char				*name;
	int					linksnum;
	char				*user;
	char				*group;
	size_t				fsize;
	time_t				timemod;
	char				type;
	blkcnt_t			blocks;
	char				linkedfile[1024];
	unsigned int		major;
	unsigned int		minor;
	struct s_afile		*next;
	char				*pateka;
}				t_afile;

void			pending(t_afile *flist, const char *flags, int argc,
				const char *folder);
int				add_child(t_afile **head, const char *path,
				const char *flags, const char *fname);
void			recbls(t_afile *childlist, const char *flags);
int				cmptime(t_afile *curr, t_afile *element);
int				sortjunk(char **argv, int argc, int flag, int x);
void			sortargvs(char **argv, int argc, int flag);
char			xattr(const char *path, t_afile *thefile);
void			getslink(const char *path, t_afile *thefile);
size_t			blockcounter(t_afile *alist);
void			clearlist(t_afile *head);
void			rtimesort(t_afile **head, t_afile *element);
void			timesort(t_afile **head, t_afile *element);
size_t			sizechecker(t_afile *alist);
void			printpermisii(mode_t filemode);
char			*getfilepath(const char *folder, const char *filename);
void			timeprinter(t_afile *dfile);
void			blsprinter(t_afile *filelist, const char *flags, int type);
void			revabcsort(t_afile **head, t_afile *element);
void			abcsort(t_afile **head, t_afile *element);
void			blslist(t_afile **head, t_afile *element, const char *flags);
t_afile			*fillelem(const char *path, char const *fname);
int				b_ls(const char *flags, const char *folder, int argc,
				char *pateka);
// char			*ft_strcat(char *dest, const char *string);

// void			ft_putnbr(int nb);
// void			ft_putstr(char *str);
// void			ft_putchar(char c);
// int				ft_atoi(char *str);

// char			*ft_strcpy(char *dst, const char *src);
// char			*ft_strncpy(char *dst, const char *src, size_t len);
// size_t			ft_strlen(const char *s);
// char			*ft_strdup(const char *s1);
// int				ft_strcmp(const char *s1, const char *s2);
// char			*ft_strchr(const char *s, int c);
// int				ft_isdigit(int c);
// int				ft_tolower(int c);
// int				ft_toupper(int c);
// void			*ft_memset(void *b, int c, size_t len);

#endif
