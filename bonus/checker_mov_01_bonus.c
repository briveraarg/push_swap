/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_mov_01_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:08:37 by brivera           #+#    #+#             */
/*   Updated: 2025/03/04 17:11:19 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	do_sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (!a || a->size < 2)
		return ;
	first = a->head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	a->head = second;
	if (a->size == 2)
		a->tail = first;
}

void	do_sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!b || b->size < 2)
		return ;
	first = b->head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	b->head = second;
	if (b->size == 2)
		b->tail = first;
}

void	do_rra(t_stack *a)
{
	t_node	*last;

	if (!a || a->size < 2)
		return ;
	last = a->tail;
	a->tail = last->prev;
	a->tail->next = NULL;
	last->prev = NULL;
	last->next = a->head;
	a->head->prev = last;
	a->head = last;
}

void	do_rrb(t_stack *b)
{
	t_node	*last;

	if (!b || b->size < 2)
		return ;
	last = b->tail;
	b->tail = last->prev;
	b->tail->next = NULL;
	last->prev = NULL;
	last->next = b->head;
	b->head->prev = last;
	b->head = last;
}
