/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:58:18 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/05 21:48:10 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** dali da se podajt **head vo clearlist, i na kraj *head = NULL;
*/

void	clearlist(t_afile *head)
{
	t_afile *temp;

	while (head)
	{
		free(head->pateka);
		free(head->user);
		free(head->group);
		free(head->name);
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	recbls(t_afile *childlist, const char *flags)
{
	t_afile *temp;

	temp = childlist;
	while (childlist)
	{
		printf("\n");
		b_ls(flags, childlist->pateka, 5, NULL);
		childlist = childlist->next;
	}
	clearlist(temp);
}

void	maddchild(t_afile **head, const char *path,
const char *flags, const char *fname)
{
	t_afile *rxfile;

	rxfile = fillelem(path, fname);
	blslist(head, rxfile, flags);
	return ;
}

void	pending(t_afile *flist, const char *flags, int argc, const char *folder)
{
	if (argc > 3 || (argc == 3 && ft_strlen(flags) < 1))
		printf("%s:\n", folder);
	blsprinter(flist, flags);
	clearlist(flist);
}
