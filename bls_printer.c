/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bls_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 21:08:57 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/01 17:47:24 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** logikata vo timeprinte, so .12 se kazvit deka max 12 karakteri ke isprintat
** od pocetok na stringot. a so &str[4], mu davam pointer da pocnit od 4 poz
** i so to da go preskoknit denot so zboroj pr. WED i space-ot posle nego
** $$$ VAZNO: funk Printpermisii mojt da se skratit, ako primat us 1 parametar
** od tip char*, i pri povik ke i se dajt ft_newstr(9), samo so FREE togas
** ne znam kako ke prajme (:
*/

#include "libft.h"

void		blsprinter(t_afile *filelist, const char *flags)
{
	int sizewidth;
	int blocks;

	blocks = 0;
	if (ft_strchr(flags, 'l'))
	{
		blocks = blockcounter(filelist);
		sizewidth = sizechecker(filelist);
		(blocks > 0 ? printf("total %d\n", blocks) : 0);
		while (filelist)
		{
			printpermisii(filelist->permisii);
			printf("%c %2d ", filelist->xattr, filelist->linksnum);
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

void		timeprinter(t_afile *dfile)
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
