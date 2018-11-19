/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 15:55:31 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/19 14:44:46 by jguleski         ###   ########.fr       */
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
	dirstrm = NULL;
	if ((ft_strchr(flags, 'd') || (dirstrm = opendir(folder)) == NULL) && 
			add_child(&filelist, folder, flags, folder))
		return (printf("b_ls: %s: %s\n", folder, strerror(errno)));
	while (dirstrm && (ent = readdir(dirstrm)) != NULL)
	{
		pateka = getfilepath(folder, ent->d_name);
		xfile = fillelem(pateka, ent->d_name);
		blslist(&filelist, xfile, flags);
		if (ft_strchr(flags, 'R') && S_ISDIR(xfile->permisii))
			add_child(&childlist, pateka, flags, ent->d_name);
		free(pateka);
		ent++;
	}
	pending(filelist, flags, argc, folder, dirstrm);
	recbls(childlist, flags);
	return (dirstrm == NULL ? 1 : closedir(dirstrm));
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
			&& flags[i] != 't' && flags[i] != 'R' && flags[i] != 'd'
			&& flags[i] != 'g' && flags[i] != 'f')
		{
			printf("b_ls: illegal option -- %c\n", flags[i]);
			printf("usage: ls [-Ralrtdgf] [file ...]\n");
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
	i = 0;
	flag = ft_newstr(1); // don't forget to use strjoin instead
	if (argc < 2)
		b_ls("", ".", argc, path);
	while (++i < argc && argv[i][0] == '-' && argv[i][1] != '-')
		if (flagchecker(argv[i]))
			ft_strcat(flag, argv[i]); // don't forget to use strjoin instead
	if (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
		i++;
	if (i == argc && argc != 1)
		return (b_ls(flag, ".", argc, path));
	sortargvs(argv, argc, i);
	while (i < argc)
	{
		if (!b_ls(flag, argv[i], argc, path) && i + 1 != argc)
			printf("\n");
		i++;
	}
	exit(0);
}
