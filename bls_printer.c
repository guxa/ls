/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bls_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 21:08:57 by jguleski          #+#    #+#             */
/*   Updated: 2018/09/27 23:46:49 by jguleski         ###   ########.fr       */
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
	int blocks;

	if (strchr(flags, 'l'))
	{
		blocks = blockcounter(filelist);
		sizewidth = sizechecker(filelist);
		printf("total %d\n", blocks);
		while (filelist)
		{
			printpermisii(filelist->permisii);
			printf("%3d ", filelist->linksnum);
			printf("%-s  %-s  ", filelist->user, filelist->group);
			printf("%*zu ", sizewidth, filelist->fsize);
			timeprinter(filelist);
			filelist = filelist->next;
		}
	}
	else
		while (filelist)
		{
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

size_t		blockcounter(t_afile *alist)
{
	size_t lsize;

	lsize = 0;
	while (alist)
	{
		if (alist->blocks)
		lsize += alist->blocks;
		alist = alist->next;
	}
	return (lsize);
}

void	timeprinter(t_afile *dfile)
{
	time_t	current_time;
	long	sixmonths;

	sixmonths = 15768000;
	current_time = time(NULL);
	if (current_time - dfile->timemodified > sixmonths)
	{
		printf("%.7s", &(ctime(&dfile->timemodified)[4]));
		printf("%5.4s ", &(ctime(&dfile->timemodified)[20]));
	}
	else
		printf("%.12s ", &(ctime(&dfile->timemodified)[4]));
	
	if (S_ISLNK(dfile->permisii))
		printf("%-s -> %s\n", dfile->name, dfile->linkedfile);
	else
		printf("%-s\n", dfile->name);
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
	if (S_ISDIR(filemode))
		printf("%c%s", 'd',permisii);
	else if (S_ISBLK(filemode))
		printf("%c%s", 'b',permisii);	
	else if (S_ISCHR(filemode))
		printf("%c%s", 'c',permisii);
	else if (S_ISFIFO(filemode))
		printf("%c%s", 'p', permisii);
	else if (S_ISREG(filemode))
		printf("%c%s", '-', permisii);
	else if (S_ISLNK(filemode))
		printf("%c%s", 'l', permisii);
	else if (S_ISSOCK(filemode))
		printf("%c%s", 's', permisii);
}

/*
**	OD timeprinter
	struct tm timenow;
	struct tm filetime;
	timenow = *localtime(&current_time);
	filetime = *localtime(&dfile->timemodified);

	if (timenow.tm_year != filetime.tm_year ||
	timenow.tm_mon - filetime.tm_mon >= 6)
		printf("%.4s ", &(ctime(&dfile->timemodified)[20]));
*/