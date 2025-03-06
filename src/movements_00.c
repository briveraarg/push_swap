/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera@student.42madrid.com <brivera>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:06:16 by brivera@stu       #+#    #+#             */
/*   Updated: 2025/03/02 02:07:38 by brivera@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack *a, int stdin)
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
	if (stdin)
		ft_putendl_fd("sa", 1);
}

void	sb(t_stack *b, int stdin)
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
	if (stdin)
		ft_putendl_fd("sb", 1);
}

void	rra(t_stack *a, int stdin)
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
	if (stdin)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *b, int stdin)
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
	if (stdin)
		ft_putendl_fd("rrb", 1);
}
