/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bls_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 21:08:57 by jguleski          #+#    #+#             */
/*   Updated: 2018/09/27 17:03:12 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** logikata vo timeprinte, so .12 se kazvit deka max 12 karakteri ke isprintat
** od pocetok na stringot. a so &str[4], mu davam pointer da pocnit od 4 poz
** i so to da go preskoknit denot so zboroj pr. WED i space-ot posle nego 
*/

#include "libft.h"

void	blsprinter(t_afile *filelist, const char *flags)
{
	int sizewidth;

	sizewidth = sizechecker(filelist);
	while (filelist)
	{
		if (strchr(flags, 'l'))
		{
			printpermisii(filelist->permisii);
			printf("%3d ", filelist->linksnum);
			printf("%-s %-s ", filelist->user, filelist->group);
			printf("%*zu ", sizewidth, filelist->fsize);
			timeprinter(filelist);

		}
		printf("%*s \n", -15, filelist->name);
		filelist = filelist->next;
	}
}

size_t		sizechecker(t_afile *alist)
{
	size_t lsize;

	lsize = 0;
	while (alist)
	{
		if (alist->fsize > lsize)
		lsize = alist->fsize;
		alist = alist->next;
	}
	return (countdigits(lsize, 10));
}

void	timeprinter(t_afile *dfile)
{
	time_t current_time;
	struct tm *timenow;
	struct tm *filetime;

	current_time = time(NULL);
	timenow = localtime(&current_time);
	filetime = localtime(&dfile->timemodified);

	printf("%.12s ", &(ctime(&dfile->timemodified)[4]));
	if (timenow->tm_year != filetime->tm_year ||
	timenow->tm_mon - filetime->tm_mon > 6)
		printf("%.4s ", &(ctime(&dfile->timemodified)[20]));
}

void	printpermisii(mode_t filemode)
{
	char *permisii;
	
	permisii = ft_newstr(9);
	permisii[0] = (filemode & S_IRUSR) ? 'r' : '-';
	permisii[1] = (filemode & S_IWUSR) ? 'w' : '-';
	permisii[2] = (filemode & S_IXUSR) ? 'x' : '-';
	permisii[3] = (filemode & S_IRGRP) ? 'r' : '-';
	permisii[4] = (filemode & S_IWGRP) ? 'w' : '-';
	permisii[5] = (filemode & S_IXGRP) ? 'x' : '-';
	permisii[6] = (filemode & S_IROTH) ? 'r' : '-';
	permisii[7] = (filemode & S_IWOTH) ? 'w' : '-';
	permisii[8] = (filemode & S_IXOTH) ? 'x' : '-';
	permisii[9] = '\0';
	printf("%s ", permisii);
}