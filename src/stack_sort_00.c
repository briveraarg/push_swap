/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:27:21 by brivera@stu       #+#    #+#             */
/*   Updated: 2025/03/03 14:43:58 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_sort(t_stack *stack_a)
{
	int		c;
	t_stack	stack_b;

	if (stack_a->size == 1)
		return ;
	c = control_num_stack(stack_a);
	if (c == TRUE)
		return ;
	else if (c == NEAR_SORTED)
		rra(stack_a, TRUE);
	if (control_num_stack(stack_a))
		return ;
	init_stack(&stack_b);
	if (stack_a->size == 3)
		stack_sort_three(stack_a);
	else if (stack_a->size == 4)
		stack_sort_four(stack_a, &stack_b);
	else
	{
		load_index_whit_timsort(stack_a);
		stack_sort_major_league(stack_a, &stack_b);
	}
	free_stack(&stack_b);
}
