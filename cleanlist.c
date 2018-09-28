/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:58:18 by jguleski          #+#    #+#             */
/*   Updated: 2018/09/27 16:58:32 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clearlist(t_afile *head)
{
	t_afile *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}