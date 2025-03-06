/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:00:17 by brivera@stu       #+#    #+#             */
/*   Updated: 2025/03/03 14:14:39 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack(t_stack *stack)
{
	if (!stack)
		return ;
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

t_node	*create_node(int data)
{
	t_node	*node;

	node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	push_back(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (!stack->head)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		stack->tail->next = node;
		node->prev = stack->tail;
		stack->tail = node;
	}
	stack->size++;
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	init_stack(stack);
}

int	control_num_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current->next != NULL && current->next->next != NULL)
	{
		if (current->data > current->next->data)
			return (FALSE);
		current = current->next;
	}
	if (current->data > current->next->data)
		return (NEAR_SORTED);
	return (TRUE);
}
/*
#include <stdio.h>

void imprimie_stack(t_stack *s)
{
	printf("\nlista");
	t_node *current =s->head;
	while (current)
	{
		printf("nodo %d ", current->data);
		printf("index %d ", current->index);
		current = current->next;
	}
	printf("\ncontador %d", s->size);
	printf("\n");
}
*/
