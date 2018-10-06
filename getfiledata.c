/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getfiledata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 00:05:04 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/05 22:09:19 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_afile		*fillelem(const char *path, char const *fname)
{
	t_afile			*thefile;
	struct stat		atribute;
	struct group	*groupx;
	struct passwd	*userx;

	thefile = (t_afile*)malloc(sizeof(t_afile));
	if (lstat(path, &atribute) != 0 || !thefile)
		return (NULL);
	userx = getpwuid(atribute.st_uid);
	groupx = getgrgid(atribute.st_gid);
	thefile->permisii = atribute.st_mode;
	thefile->linksnum = atribute.st_nlink;
	thefile->user = ft_strdup(userx->pw_name);
	thefile->group = ft_strdup(groupx->gr_name);
	thefile->fsize = atribute.st_size;
	thefile->timemod = atribute.st_mtime;
	thefile->name = ft_strdup(fname);
	thefile->type = (fname[0] == '.' ? 'a' : 'b');
	thefile->blocks = atribute.st_blocks;
	thefile->next = NULL;
	thefile->fnano = atribute.st_mtimespec;
	thefile->pateka = ft_strdup(path);
	if (S_ISLNK(thefile->permisii))
		getslink(path, thefile);
	return (thefile);
}

void		getslink(const char *path, t_afile *thefile)
{
	ssize_t len;

	len = readlink(path, thefile->linkedfile, sizeof(thefile->linkedfile) - 1);
	if (len != -1)
		thefile->linkedfile[len] = '\0';
	else
	{
		perror(path);
		exit(-1);
	}
}
