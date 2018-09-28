/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blstfuncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:41:48 by jguleski          #+#    #+#             */
/*   Updated: 2018/09/27 17:01:52 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	blslist(t_afile **head, t_afile *element, const char *flags)
{
	if (!element || (!(ft_strchr(flags, 'a')) && element->type == 'a'))
		return ;
	if (*head == NULL)
	{
		*head = element;
		return ;
	}
	if (ft_strchr(flags, 't') && ft_strchr(flags, 'r'))
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
	while (curr->next && (curr->timemodified - element->timemodified >= 0))
	{
		prev = curr;
		curr = curr->next;
	}
	if (curr->timemodified - element->timemodified <= 0)
	{
		if (!prev)
		{
			*head = element;
			//curr->next = NULL;
		}
		else
			prev->next = element;
		element->next = curr;
	}
	else
		curr->next = element;
}

void	rtimesort(t_afile **head, t_afile *element)
{
	t_afile	*curr;
	t_afile *prev;

	prev = NULL;
	curr = *head;
	while (curr->next && (curr->timemodified - element->timemodified <= 0))
	{
		prev = curr;
		curr = curr->next;
	}
	if (curr->timemodified - element->timemodified >= 0)
	{
		if (!prev)
		{
			*head = element;
			//curr->next = NULL;
		}		
		else
			prev->next = element;
		element->next = curr;
	}
	else
		curr->next = element;
}
