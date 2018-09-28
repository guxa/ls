/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:58:18 by jguleski          #+#    #+#             */
/*   Updated: 2018/09/27 21:42:28 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clearlist(t_afile *head)
{
	t_afile *temp;

	while (head)
	{
		free(head->name);
		temp = head;
		head = head->next;
		free(temp);
	}
	// dali da se podajt **head, i na kraj *head = NULL;
}