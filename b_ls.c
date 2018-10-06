/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 15:55:31 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/05 21:47:50 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			b_ls(const char *flags, const char *folder, int argc, char *pateka)
{
	DIR				*dirstrm;
	struct dirent	*ent;
	t_afile			*xfile;
	t_afile			*filelist;
	t_afile			*childlist;

	childlist = NULL;
	filelist = NULL;
	if ((dirstrm = opendir(folder)) == NULL)
		return (printf("b_ls: %s: %s\n", folder, strerror(errno)));
	while ((ent = readdir(dirstrm)) != NULL)
	{
		pateka = getfilepath(folder, ent->d_name);
		xfile = fillelem(pateka, ent->d_name);
		blslist(&filelist, xfile, flags);
		if (strchr(flags, 'R') && S_ISDIR(xfile->permisii))
			maddchild(&childlist, pateka, flags, ent->d_name);
		free(pateka);
		ent++;
	}
	pending(filelist, flags, argc, folder);
	recbls(childlist, flags);
	closedir(dirstrm);
	return (0);
}

char		*getfilepath(const char *folder, const char *filename)
{
	char *pateka;

	pateka = ft_newstr(ft_strlen(folder) + ft_strlen(filename) + 1);
	if (pateka)
	{
		ft_strcpy(pateka, folder);
		ft_strcat(pateka, "/");
		ft_strcat(pateka, filename);
	}
	return (pateka);
}

int			flagchecker(const char *flags)
{
	int i;

	i = 0;
	while (flags[++i])
		if (flags[i] != 'a' && flags[i] != 'l' && flags[i] != 'r'
			&& flags[i] != 't' && flags[i] != 'R')
		{
			printf("b_ls: illegal option -- %c\n", flags[i]);
			printf("usage: ls [-Ralrt] [file ...]\n");
			exit(0);
		}
	return (1);
}

int			main(int argc, char **argv)
{
	int		i;
	char	*flag;
	char	*path;

	path = NULL;
	i = 1;
	flag = ft_newstr(50);
	if (argc < 2)
		b_ls("", ".", argc, path);
	while (i < argc && argv[i][0] == '-')
	{
		if (flagchecker(argv[i]))
			ft_strcat(flag, argv[i]);
		i++;
	}
	if (i == argc && argc != 1)
		b_ls(flag, ".", argc, path);
	sortargvs(argv, argc, i);
	while (i < argc)
	{
		if (!b_ls(flag, argv[i], argc, path) && i + 1 != argc)
			printf("\n");
		i++;
	}
	exit(0);
}
