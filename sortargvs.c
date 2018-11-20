/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortargvs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 16:49:08 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/19 15:51:33 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void		sortargvs(char **argv, int argc, int flag)
{
	int		i;
	char	*temp;
	int		x;

	temp = NULL;
	i = flag;
	x = sortjunk(argv, argc, flag, 0);
	while (i < argc - 1)
	{
		if (i == x)
			i++;
		if (i < argc - 1 && ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			temp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = temp;
			i = flag - 1;
		}
		i++;
	}
}

int			sortjunk(char **argv, int argc, int flag, int x)
{
	int		i;
	char	*temp;
	DIR		*dirstream;
	DIR		*xstream;

	i = flag - 1;
	while (++i < argc - 1)
	{
		xstream = NULL;
		dirstream = NULL;
		if ((dirstream = opendir(argv[i]))
			&& (xstream = opendir(argv[i + 1])) == NULL)
		{
			temp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = temp;
			x = i;
			i = flag - 1;
		}
		if (dirstream)
			closedir(dirstream);
		if (xstream)
			closedir(xstream);
	}
	return (x == 0 ? i : x);
}

int			cmptime(t_afile *curr, t_afile *element)
{
	if (curr->fnano.tv_sec - element->fnano.tv_sec < 0)
		return (1);
	else if (curr->fnano.tv_sec - element->fnano.tv_sec == 0)
	{
		if (curr->fnano.tv_nsec - element->fnano.tv_nsec < 0)
			return (1);
		if (curr->fnano.tv_nsec == element->fnano.tv_nsec
			&& (ft_strcmp(curr->name, element->name) > 0))
			return (1);
	}
	return (0);
}
