/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:31:15 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/31 17:31:48 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl(char const *str)
{
	if (!str)
		return ;
	while (str[0])
	{
		write(1, &str[0], 1);
		str++;
	}
	write(1, "\n", 1);
}