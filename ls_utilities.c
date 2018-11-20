/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:58:18 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/20 01:08:09 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

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
		ft_printf("\n");
		b_ls(flags, childlist->pateka, 5, NULL);
		childlist = childlist->next;
	}
	clearlist(temp);
}

int		add_child(t_afile **head, const char *path,
const char *flags, const char *fname)
{
	t_afile *rxfile;

	if (errno && errno != ENOTDIR)
		return (-1);
	if (ft_strcmp(fname, ".") == 0 || ft_strcmp(fname, "..") == 0)
		return (-1);
	if ((rxfile = fillelem(path, fname, g_uflag)) == NULL)
		return (-1);
	blslist(head, rxfile, flags);
	return (0);
}

void	init_lists(t_afile **filelist, t_afile **childlist, DIR **dirstrm,
					const char *flags)
{
	errno = 0;
	g_uflag = (ft_strchr(flags, 'u') == NULL ? '0' : 'u');
	g_rflag = (ft_strchr(flags, 'R') == NULL ? 0 : 1);
	*childlist = NULL;
	*filelist = NULL;
	*dirstrm = NULL;
}

void	pending(t_afile *flist, const char *flags, int argc,
				const char *folder)
{
	if (argc - 2 > ((int)ft_strlen(flags) / 2))
		ft_printf("%s:\n", folder);
	blsprinter(flist, flags, argc);
	clearlist(flist);
}
