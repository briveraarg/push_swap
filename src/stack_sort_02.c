/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:37:49 by brivera@stu       #+#    #+#             */
/*   Updated: 2025/03/03 14:07:45 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	calculator_range(int size)
{
	int	range;

	range = 0;
	while ((range * range) <= size)
		range++;
	range--;
	return (range);
}

int	counter_rotation(t_node *stack, int index)
{
	int	counter;

	counter = 0;
	while (stack && stack->index != index)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

void	k_sort_phase_one(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	range;

	i = 0;
	range = calculator_range(stack_a->size) * 13 / 10;
	while (stack_a->head)
	{
		if (stack_a->head->index <= i)
		{
			pb(stack_a, stack_b, TRUE);
			i++;
		}
		else if (stack_a->head->index <= i + range)
		{
			pb(stack_a, stack_b, TRUE);
			i++;
			if (!(stack_a->head->index <= i + range))
				rr(stack_a, stack_b, TRUE);
			else
				rb(stack_b, TRUE);
		}
		else
			ra(stack_a, TRUE);
	}
}

void	k_sort_phase_two(t_stack *stack_a, t_stack *stack_b, int size_a)
{
	int	rb_count;
	int	rrb_count;

	while (size_a - 1 >= 0)
	{
		rb_count = counter_rotation(stack_b->head, size_a - 1);
		rrb_count = stack_b->size - rb_count;
		if (rb_count <= rrb_count)
			while (stack_b->head->index != size_a - 1)
				rb(stack_b, TRUE);
		else
			while (stack_b->head->index != size_a - 1)
				rrb(stack_b, TRUE);
		pa(stack_a, stack_b, TRUE);
		size_a--;
	}
}

void	stack_sort_major_league(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;

	size_a = stack_a->size;
	if (stack_a->size >= 5 && stack_a->size <= 8)
	{
		if (stack_a->size == 8)
			size_a = 4;
		else
			size_a = 3;
		stack_sort_five_and_eight(stack_a, stack_b, size_a);
	}
	else
	{
		k_sort_phase_one(stack_a, stack_b);
		k_sort_phase_two(stack_a, stack_b, size_a);
	}
}
