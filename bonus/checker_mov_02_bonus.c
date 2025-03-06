/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_mov_02_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:10:15 by brivera           #+#    #+#             */
/*   Updated: 2025/03/04 17:15:05 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	do_ra(t_stack *a)
{
	t_node	*first;

	if (!a || a->size < 2)
		return ;
	first = a->head;
	a->head = first->next;
	a->head->prev = NULL;
	first->next = NULL;
	first->prev = a->tail;
	a->tail->next = first;
	a->tail = first;
}

void	do_rb(t_stack *b)
{
	t_node	*first;

	if (!b || b->size < 2)
		return ;
	first = b->head;
	b->head = first->next;
	b->head->prev = NULL;
	first->next = NULL;
	first->prev = b->tail;
	b->tail->next = first;
	b->tail = first;
}

void	do_pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!b || !b->head)
		return ;
	node = b->head;
	b->head = b->head->next;
	if (b->head)
		b->head->prev = NULL;
	else
		b->tail = NULL;
	b->size--;
	if (!a->head)
	{
		a->head = node;
		a->tail = node;
		node->next = NULL;
	}
	else
	{
		node->next = a->head;
		a->head->prev = node;
		a->head = node;
	}
	a->size++;
}

void	do_pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a || !a->head)
		return ;
	node = a->head;
	a->head = a->head->next;
	if (a->head)
		a->head->prev = NULL;
	else
		a->tail = NULL;
	a->size--;
	if (!b->head)
	{
		b->head = node;
		b->tail = node;
		node->next = NULL;
	}
	else
	{
		node->next = b->head;
		b->head->prev = node;
		b->head = node;
	}
	b->size++;
}
