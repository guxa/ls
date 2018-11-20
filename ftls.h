/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:05:04 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/19 17:44:44 by jguleski         ###   ########.fr       */
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
	char				type;
	blkcnt_t			blocks;
	char				linkedfile[1024];
	unsigned int		major;
	unsigned int		minor;
	struct s_afile		*next;
	char				*pateka;
}				t_afile;

char			g_uflag;

void			init_lists(t_afile **filelist, t_afile **childlist,
							DIR **dirstrm, const char *flags);
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
t_afile			*fillelem(const char *path, char const *fname, char uflag);
int				b_ls(const char *flags, const char *folder, int argc,
				char *pateka);

#endif
