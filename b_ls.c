/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 15:55:31 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/19 22:11:38 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

int			b_ls(const char *flags, const char *folder, int argc, char *pateka)
{
	DIR				*dirstrm;
	struct dirent	*ent;
	t_afile			*xfile;
	t_afile			*filelist;
	t_afile			*childlist;

	init_lists(&filelist, &childlist, &dirstrm, flags);
	if ((ft_strchr(flags, 'd') || (dirstrm = opendir(folder)) == NULL) &&
			add_child(&filelist, folder, flags, folder))
		return (ft_printf("b_ls: %s: %s\n", folder, strerror(errno)));
	while (dirstrm && (ent = readdir(dirstrm)) != NULL)
	{
		pateka = getfilepath(folder, ent->d_name);
		xfile = fillelem(pateka, ent->d_name, g_uflag);
		blslist(&filelist, xfile, flags);
		if (ft_strchr(flags, 'R') && S_ISDIR(xfile->permisii))
			add_child(&childlist, pateka, flags, ent->d_name);
		free(pateka);
		ent++;
	}
	pending(filelist, flags, (dirstrm == NULL ? 0 : argc), folder);
	recbls(childlist, flags);
	return (dirstrm == NULL ? 1 : closedir(dirstrm));
}

char		*getfilepath(const char *folder, const char *filename)
{
	char *pateka;

	pateka = ft_strnew(ft_strlen(folder) + ft_strlen(filename) + 1);
	if (pateka)
	{
		ft_strcpy(pateka, folder);
		ft_strcat(pateka, "/");
		ft_strcat(pateka, filename);
	}
	return (pateka);
}

void		flagchecker(char **flags, const char *arg)
{
	int		i;
	char	*temp;

	i = 0;
	while (arg[++i])
		if (arg[i] != 'a' && arg[i] != 'l' && arg[i] != 'r'
			&& arg[i] != 't' && arg[i] != 'R' && arg[i] != 'd'
			&& arg[i] != 'g' && arg[i] != 'f' && arg[i] != 'u')
		{
			ft_printf("b_ls: illegal option -- %c\n", arg[i]);
			ft_printf("usage: ls [-Ralrtdgfu] [file ...]\n");
			exit(0);
		}
	temp = *flags;
	*flags = ft_strjoin(*flags, arg);
	free(temp);
}

int			main(int argc, char **argv)
{
	int		i;
	char	*flag;
	char	*path;

	path = NULL;
	i = 0;
	flag = ft_strnew(1);
	if (argc < 2)
		b_ls("", ".", argc, path);
	while (++i < argc && argv[i][0] == '-' && argv[i][1] != '-')
		flagchecker(&flag, argv[i]);
	if (ft_strchr(flag, 'f'))
		flagchecker(&flag, "-a");
	if (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
		i++;
	if (i == argc && argc != 1)
		return (b_ls(flag, ".", argc, path));
	sortargvs(argv, argc, i);
	while (i < argc)
	{
		if (!b_ls(flag, argv[i], argc, path) && i + 1 != argc)
			ft_printf("\n");
		i++;
	}
	exit(0);
}
