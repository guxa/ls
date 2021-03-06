/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bls_permis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:09:33 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/19 23:15:35 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void		filetype(mode_t filemode)
{
	if (S_ISDIR(filemode))
		ft_printf("%c", 'd');
	else if (S_ISBLK(filemode))
		ft_printf("%c", 'b');
	else if (S_ISCHR(filemode))
		ft_printf("%c", 'c');
	else if (S_ISFIFO(filemode))
		ft_printf("%c", 'p');
	else if (S_ISREG(filemode))
		ft_printf("%c", '-');
	else if (S_ISLNK(filemode))
		ft_printf("%c", 'l');
	else if (S_ISSOCK(filemode))
		ft_printf("%c", 's');
}

void		printpermisii(mode_t filemode)
{
	char *permisii;

	filetype(filemode);
	permisii = ft_strnew(9);
	permisii[0] = (filemode & S_IRUSR) ? 'r' : '-';
	permisii[1] = (filemode & S_IWUSR) ? 'w' : '-';
	permisii[2] = (filemode & S_IXUSR) ? 'x' : '-';
	permisii[3] = (filemode & S_IRGRP) ? 'r' : '-';
	permisii[4] = (filemode & S_IWGRP) ? 'w' : '-';
	permisii[5] = (filemode & S_IXGRP) ? 'x' : '-';
	permisii[6] = (filemode & S_IROTH) ? 'r' : '-';
	permisii[7] = (filemode & S_IWOTH) ? 'w' : '-';
	permisii[8] = (filemode & S_IXOTH) ? 'x' : '-';
	if (filemode & S_ISUID)
		permisii[2] = (filemode & S_IXUSR) ? 's' : 'S';
	if (filemode & S_ISGID)
		permisii[5] = (filemode & S_IXGRP) ? 's' : 'S';
	if (filemode & S_ISVTX)
		permisii[8] = (filemode & S_IXOTH) ? 't' : 'T';
	ft_printf("%s", permisii);
	free(permisii);
}
