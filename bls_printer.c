/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bls_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 21:08:57 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/19 15:02:22 by jguleski         ###   ########.fr       */
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

#include "ftls.h"

void		blsprinter(t_afile *list, const char *flags, int ftype)
{
	int sizewidth;

	if (ft_strchr(flags, 'l') || ft_strchr(flags, 'g'))
	{
		sizewidth = sizechecker(list);
		(ftype == 0 ? 0 : printf("total %zu\n", blockcounter(list)));
		while (list)
		{
			printpermisii(list->permisii);
			printf("  %2d ", list->linksnum);
			printf("%-s  %-s  ", (ft_strchr(flags, 'g') ? "" : list->user), list->group);
			if (S_ISCHR(list->permisii) || S_ISBLK(list->permisii))
				printf("%u, %u ", list->major, list->minor);
			else
				printf("%*zu ", sizewidth, list->fsize);
			timeprinter(list);
			list = list->next;
		}
	}
	else
		while (list)
		{
			printf("%*s \n", -15, list->name);
			list = list->next;
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
	if (current_time - dfile->timemod > sixmonths)
	{
		printf("%.7s", &(ctime(&dfile->timemod)[4]));
		printf("%5.4s ", &(ctime(&dfile->timemod)[20]));
	}
	else
		printf("%.12s ", &(ctime(&dfile->timemod)[4]));
	if (S_ISLNK(dfile->permisii))
		printf("%-s -> %s\n", dfile->name, dfile->linkedfile);
	else
		printf("%-s\n", dfile->name);
}
