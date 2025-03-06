/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:06:01 by brivera@stu       #+#    #+#             */
/*   Updated: 2025/03/03 14:45:42 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_sort_three(t_stack *stack)
{
	if (stack->head->data > stack->head->next->data
		&& stack->head->data > stack->head->next->next->data)
		ra(stack, TRUE);
	else if (stack->head->next->data > stack->head->data
		&& stack->head->next->data > stack->head->next->next->data)
		rra(stack, TRUE);
	if (stack->head->data > stack->head->next->data)
		sa(stack, TRUE);
}

void	stack_sort_four(t_stack *stack_a, t_stack *stack_b)
{
	pb(stack_a, stack_b, TRUE);
	stack_sort_three(stack_a);
	if (stack_b->head->data > stack_a->tail->data)
	{
		pa(stack_a, stack_b, TRUE);
		ra(stack_a, TRUE);
	}
	else if (stack_b->head->data > stack_a->tail->prev->data)
	{
		rra(stack_a, TRUE);
		pa(stack_a, stack_b, TRUE);
		ra(stack_a, TRUE);
		ra(stack_a, TRUE);
	}
	else if (stack_b->head->data > stack_a->head->data)
	{
		pa(stack_a, stack_b, TRUE);
		sa(stack_a, TRUE);
	}
	else
		pa(stack_a, stack_b, TRUE);
}

void	stack_sort_five_and_eight(t_stack *stack_a, t_stack *stack_b, int lim)
{
	int	count;

	count = 0;
	while (stack_a->size > lim)
	{
		if (stack_a->head->index == count)
		{
			pb(stack_a, stack_b, TRUE);
			count++;
		}
		else if (stack_a->tail->index == count)
		{
			rra(stack_a, TRUE);
			pb(stack_a, stack_b, TRUE);
			count++;
		}
		else
			ra(stack_a, TRUE);
	}
	if (stack_a->size == 3)
		stack_sort_three(stack_a);
	else
		stack_sort_four(stack_a, stack_b);
	while (stack_b->size > 0)
		pa(stack_a, stack_b, TRUE);
}
