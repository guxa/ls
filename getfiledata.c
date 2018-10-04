/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getfiledata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 00:05:04 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/03 16:40:42 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_afile		*fillelem(const char *path, char const *fname)
{
	t_afile *thefile;
	struct stat atribute;	
	struct group *groupx;
	struct passwd *userx;

	thefile = (t_afile*)malloc(sizeof(t_afile));
	if (lstat(path, &atribute) != 0 || !thefile)
		return (NULL);
	userx = getpwuid(atribute.st_uid);
	groupx = getgrgid(atribute.st_gid);
	thefile->permisii = atribute.st_mode;
	thefile->xattr = ' '; // xattr(path, thefile); //
	thefile->linksnum = atribute.st_nlink;
	thefile->user = userx->pw_name;
	thefile->group = groupx->gr_name;
	thefile->fsize = atribute.st_size;
	thefile->timemod = atribute.st_mtime;
	thefile->name = ft_strdup(fname); //(char *)fname; imav problemi so ova
	thefile->type = (fname[0] == '.' ? 'a' : 'b');
	thefile->blocks = atribute.st_blocks;
	thefile->next = NULL;
	thefile->fnano = atribute.st_mtimespec;
	if (S_ISLNK(thefile->permisii))
		getslink(path, thefile);
	return (thefile);
}

void	getslink(const char *path, t_afile *thefile)
{
		ssize_t len;

		len = readlink(path, thefile->linkedfile, sizeof(thefile->linkedfile) - 1);
		if (len != -1)
			thefile->linkedfile[len] = '\0';
		else
		{
			perror(path);
			exit (-1);
		}	
}

char	xattr(const char *path, t_afile *thefile)
{
	ssize_t len;
	//acl_t	acl;

	len = 0;
	if (thefile->name[0] == '.')
		return (' ');
	//acl = NULL;
	len = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	//acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (len == -1)
	{
		perror(path);
		return (' ');
	}
	else if (len > 0)
		return ('@');
	// else if (acl)
	// {
	// 	acl_free(acl);
	// 	acl = NULL;
	// 	return '+';
	// }
	else
		return ' ';
}