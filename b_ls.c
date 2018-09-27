/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 15:55:31 by jguleski          #+#    #+#             */
/*   Updated: 2018/09/27 16:33:04 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		b_ls(const char *flags, const char *folder)
{
	DIR		*dirstrm;
	struct	dirent *ent;
	t_afile	*xfile;
	t_afile	*filelist;
	char	*pateka;

	xfile = NULL;
	filelist = NULL;
	if(!flags)
		flags = "";
	if((dirstrm = opendir(folder)) == NULL)
		return (perror(folder));
	while ((ent = readdir(dirstrm)) != NULL)
	{
		pateka = getfilepath(folder, ent->d_name);
		xfile = fillelem(pateka, ent->d_name);
		blslist(&filelist, xfile, flags);
		free(pateka);
		ent++;
	}
	blsprinter(filelist, flags);
	clearlist(filelist);
	closedir(dirstrm);
	//exit(0);
}

char	*getfilepath(const char *folder, const char *filename)
{
	char *pateka;

	pateka = ft_newstr(ft_strlen(folder) + ft_strlen(filename) + 1);
	if (pateka)
	{
		ft_strcpy(pateka, folder);
		strcat(pateka, "/");
		strcat(pateka, filename);
	}
	return pateka;
}

t_afile			*fillelem(const char *path, char const *fname)
{
	t_afile *thefile;
	struct stat atribute;	
	struct group *groupx;
	struct passwd *userx;

	//userx = NULL;
	//groupx = NULL;
	thefile = (t_afile*)malloc(sizeof(t_afile));
	if (stat(path, &atribute) != 0 || !thefile)
		return (NULL);
	userx = getpwuid(atribute.st_uid);
	groupx = getgrgid(atribute.st_gid);
	thefile->permisii = atribute.st_mode;
	thefile->fsize = atribute.st_size;
	thefile->linksnum = atribute.st_nlink;
	thefile->user = userx->pw_name;
	thefile->group = groupx->gr_name;
	thefile->timemodified = atribute.st_mtime;
	thefile->timestr = NULL; //ke zatrebit ft_strdup(ctime(&thefile->timemodified));
	thefile->name = (char *)fname;
	thefile->type = (fname[0] == '.' ? 'a' : 'b');
	thefile->next = NULL;
	return (thefile);
}

char	flagchecker(const char *flags)
{
	int i;

	i = 0;
	while (flags[++i])
		if (flags[i] != 'a' && flags[i] != 'l' && flags[i] != 'r'
			&& flags[i] != 't')
		{
			printf("b_ls: illegal option -- %c\n", flags[i]);
			printf("usage: ls [-alrt] [file ...]\n");
			return 'E';
		}

	return ('n');
}

int main(int argc, char **argv)
{
	int i;
	char *flag;

	i = 1;
	flag = NULL;
	if (argc < 2)
		b_ls(flag, ".");
	else if (argv[1][0] == '-')
	{
		flag = argv[1];
		i++;
	}
	if (flag && flagchecker(argv[1]) == 'E')
		return (0);
	if (argc == 2 && flag)
		b_ls(argv[1], ".");
	while (i < argc)
	{
		if (argc > 2)
			printf("%s:\n", argv[i]);
		b_ls(flag, argv[i]);
		if (i + 1 != argc)
			printf("\n");
		i++;
	}
	return (0);
}

/*
https://stackoverflow.com/questions/9101590/fprintf-and-ctime-without-passing-n-from-ctime
https://openclassrooms.com/forum/sujet/segment-fault-pour-getpwuid-et-getgrgid
https://stackoverflow.com/questions/10446526/get-last-modified-time-of-file-in-linux
https://linux.die.net/man/2/stat
http://man7.org/linux/man-pages/man3/ctime.3.html
https://www.garron.me/en/go2linux/ls-file-permissions.html
*/