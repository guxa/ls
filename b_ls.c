/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 15:55:31 by jguleski          #+#    #+#             */
/*   Updated: 2018/09/30 17:42:14 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			b_ls(const char *flags, const char *folder, int argc)
{
	DIR		*dirstrm;
	struct	dirent *ent;
	t_afile	*xfile;
	t_afile	*filelist;
	char	*pateka;

	xfile = NULL;
	filelist = NULL;
	if((dirstrm = opendir(folder)) == NULL)
		return printf("b_ls: %s: %s\n", folder, strerror(errno));
	while ((ent = readdir(dirstrm)) != NULL)
	{
		pateka = getfilepath(folder, ent->d_name);
		xfile = fillelem(pateka, ent->d_name);
		blslist(&filelist, xfile, flags);
		free(pateka);
		ent++;
	}
	if (argc > 3 || (argc == 3 && ft_strlen(flags) < 1))
		printf("%s:\n", folder);
	blsprinter(filelist, flags);
	clearlist(filelist);
	closedir(dirstrm);
	if (errno)
		printf("\n%s", strerror(errno));
	return (0);
}

char		*getfilepath(const char *folder, const char *filename)
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

int		flagchecker(const char *flags)
{
	int i;

	i = 0;
	while (flags[++i])
		if (flags[i] != 'a' && flags[i] != 'l' && flags[i] != 'r'
			&& flags[i] != 't')
		{
			printf("b_ls: illegal option -- %c\n", flags[i]);
			printf("usage: ls [-alrt] [file ...]\n");
			return (0);
		}

	return (1);
}

int main(int argc, char **argv)
{
	int i;
	char *flag;

	i = 1;
	flag = NULL;
	if (argc < 2)
		b_ls(flag, ".", argc);
	else if (argv[1][0] == '-')
	{
		if ((flag = argv[1]) && !flagchecker(argv[1]))
			return (0);
		i++;
	}
	if (argc == 2 && flag)
		b_ls(argv[1], ".", argc);
	if (!flag)
		flag = "";
	sortargvs(argv, argc, i);
	while (i < argc)
	{
		if (!b_ls(flag, argv[i], argc) && i + 1 != argc)
			printf("\n");
		i++;
	}
	exit(0);
}

void	sortargvs(char **argv, int argc, int flag)
{
	int i;
	char *temp;

	temp = NULL;
	i = flag;
	while (i < argc - 1)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			temp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = temp;
			i = flag - 1;
		}
		i++;
	}
}

/*
https://stackoverflow.com/questions/9101590/fprintf-and-ctime-without-passing-n-from-ctime
https://openclassrooms.com/forum/sujet/segment-fault-pour-getpwuid-et-getgrgid
https://stackoverflow.com/questions/10446526/get-last-modified-time-of-file-in-linux
https://linux.die.net/man/2/stat
http://man7.org/linux/man-pages/man3/ctime.3.html
https://www.garron.me/en/go2linux/ls-file-permissions.html
*/

/*
** linija 121 (vo while) e za da printat ime na folder 
** i prazno mesto megu folderi ko ke imat pojke folderi, 
** ama ne ko ke imat flag i 1 folder
*/ 