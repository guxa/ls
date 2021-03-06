/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blstfuncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:41:48 by jguleski          #+#    #+#             */
/*   Updated: 2018/11/19 15:21:37 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void	blslist(t_afile **head, t_afile *element, const char *flags)
{
	t_afile	*temp;

	if (!element || (!(ft_strchr(flags, 'a')) && element->type == 'a'))
		return (clearlist(element));
	if (*head == NULL)
	{
		*head = element;
		return ;
	}
	else if (ft_strchr(flags, 'f'))
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = element;
	}
	else if (ft_strchr(flags, 't') && ft_strchr(flags, 'r'))
		rtimesort(head, element);
	else if (flags && ft_strchr(flags, 'r'))
		revabcsort(head, element);
	else if (ft_strchr(flags, 't'))
		timesort(head, element);
	else
		abcsort(head, element);
}

void	abcsort(t_afile **head, t_afile *element)
{
	t_afile	*curr;
	t_afile *prev;

	prev = NULL;
	curr = *head;
	while (curr->next && (ft_strcmp(curr->name, element->name) <= 0))
	{
		prev = curr;
		curr = curr->next;
	}
	if (ft_strcmp(curr->name, element->name) >= 0)
	{
		if (!prev)
			*head = element;
		else
			prev->next = element;
		element->next = curr;
	}
	else
		curr->next = element;
}

void	revabcsort(t_afile **head, t_afile *element)
{
	t_afile	*curr;
	t_afile *prev;

	prev = NULL;
	curr = *head;
	while (curr->next && (ft_strcmp(curr->name, element->name) >= 0))
	{
		prev = curr;
		curr = curr->next;
	}
	if (ft_strcmp(curr->name, element->name) <= 0)
	{
		if (!prev)
			*head = element;
		else
			prev->next = element;
		element->next = curr;
	}
	else
		curr->next = element;
}

void	timesort(t_afile **head, t_afile *element)
{
	t_afile	*curr;
	t_afile *prev;

	prev = NULL;
	curr = *head;
	while (curr->next && cmptime(element, curr))
	{
		prev = curr;
		curr = curr->next;
	}
	if (cmptime(curr, element))
	{
		if (!prev)
			*head = element;
		else
			prev->next = element;
		element->next = curr;
	}
	else
	{
		prev = curr->next;
		curr->next = element;
		element->next = prev;
	}
}

void	rtimesort(t_afile **head, t_afile *element)
{
	t_afile	*curr;
	t_afile *prev;

	prev = NULL;
	curr = *head;
	while (curr->next && cmptime(curr, element))
	{
		prev = curr;
		curr = curr->next;
	}
	if (cmptime(element, curr))
	{
		if (!prev)
			*head = element;
		else
			prev->next = element;
		element->next = curr;
	}
	else
		curr->next = element;
}
