/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortargvs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 16:49:08 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/01 16:52:12 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
