/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_04.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera@student.42madrid.com <brivera>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:08:23 by brivera@stu       #+#    #+#             */
/*   Updated: 2025/03/02 21:31:27 by brivera@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	*save_data_in_array(t_stack *stack)
{
	int		*arr;
	t_node	*current;
	int		i;

	if (!stack || stack->size == 0)
		return (NULL);
	arr = (int *)ft_calloc(stack->size, sizeof(int));
	if (!arr)
		return (NULL);
	current = stack->head;
	i = 0;
	while (current)
	{
		arr[i] = current->data;
		current = current->next;
		i++;
	}
	return (arr);
}

static void	save_index_in_stack(t_stack *stack, int *arr)
{
	t_node	*current;
	int		i;

	current = stack->head;
	while (current)
	{
		i = 0;
		while (i < stack->size)
		{
			if (current->data == arr[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

static void	phase_one(int *arr, int n)
{
	int	i;
	int	right;

	i = 0;
	while (i < n)
	{
		right = i + RUN - 1;
		if (right >= n)
			right = n - 1;
		insertion_sort(arr, i, right);
		i = i + RUN;
	}
}

static void	phase_two(int *arr, int n)
{
	int	right;
	int	size;
	int	left;
	int	mid;

	size = RUN;
	while (size < n)
	{
		left = 0;
		while (left < n)
		{
			mid = left + size - 1;
			right = left + 2 * size - 1;
			if (right >= n)
				right = n - 1;
			if (mid < right)
				merge(arr, left, right, mid);
			left += 2 * size;
		}
		size *= 2;
	}
}

void	load_index_whit_timsort(t_stack *stack_a)
{
	int	*arr;
	int	n;

	arr = save_data_in_array(stack_a);
	if (!arr)
	{
		free_stack(stack_a);
		error_and_exit("Error ft_calloc");
	}
	n = stack_a->size;
	phase_one(arr, n);
	phase_two(arr, n);
	save_index_in_stack(stack_a, arr);
	free(arr);
}
