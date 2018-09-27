/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blstfuncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:41:48 by jguleski          #+#    #+#             */
/*   Updated: 2018/09/26 20:21:11 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			blslist(t_afile **head, t_afile *element, const char *flags)
{
	t_afile **realhead;
	//t_afile *prev;
	if (!element)
		return ;
	if (*head == NULL)
	{
		*head = element;
		return ;
	}
	//prev = NULL;
	//curr = *head;
	if (flags && ft_strchr(flags, 'r')) //flagchecker(flags) == 'r')
		revabcsort(head, element);
	else
		abcsort(head, element);
	if (ft_strchr(flags, 't'))
		timesort(head, element);
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

char	flagchecker(const char *flags)
{
	int i;

	i = 0;
	while (flags[++i])
		if (flags[i] != 'a' && flags[i] != 'l' && flags[i] != 'r'
			&& flags[i] != 't')
		{
			printf("b_ls: illegal option -- %c\n", flags[i]);
			printf("usage: ls [-alrt] [file ...]\n");
			return 'E';
		}

	return ('n');
}

void	timesort(t_afile **head, t_afile *element)
{
	t_afile	*curr;
	t_afile *prev;

	prev = NULL;
	curr = *head;
	while (curr->next && (curr->timemodified - element->timemodified > 0))
	{
		prev = curr;
		curr = curr->next;
	}
	if (curr->timemodified - element->timemodified < 0)
	{
		if (!prev)
		{
			*head = element;
			curr->next = NULL;
		}			
		else
			prev->next = element;
		element->next = curr;
	}
	else
		curr->next = element;
}