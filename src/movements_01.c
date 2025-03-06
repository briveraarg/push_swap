/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:21:27 by brivera@stu       #+#    #+#             */
/*   Updated: 2025/03/03 14:06:20 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack *a, int stdin)
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
	if (stdin)
		ft_putendl_fd("ra", 1);
}

void	rb(t_stack *b, int stdin)
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
	if (stdin)
		ft_putendl_fd("rb", 1);
}

static void	aux_stdin(int stdin, char m)
{
	if (stdin)
	{
		if (m == 'b')
			ft_putendl_fd("pb", 1);
		else
			ft_putendl_fd("pa", 1);
	}
}

void	pa(t_stack *a, t_stack *b, int stdin)
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
	aux_stdin(stdin, 'a');
}

void	pb(t_stack *a, t_stack *b, int stdin)
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
	aux_stdin(stdin, 'b');
}
