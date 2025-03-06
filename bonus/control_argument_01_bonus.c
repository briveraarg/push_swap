/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_argument_01_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:28:27 by brivera           #+#    #+#             */
/*   Updated: 2025/03/05 14:28:32 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	ft_has_duplicates(t_stack *stack, int num)
{
	t_node	*current;

	if (!stack)
		return (0);
	current = stack->head;
	while (current)
	{
		if (current->data == num)
			return (TRUE);
		current = current->next;
	}
	return (FALSE);
}

static void	create_node_stack(t_stack *stack, int num)
{
	t_node	*num_node;

	num_node = create_node(num);
	if (!num_node)
	{
		free_stack(stack);
		error_and_exit("Error create node");
	}
	push_back(stack, num_node);
}

void	parse_int_from_str(int argc, char **argv, t_stack *stack)
{
	int		i;
	size_t	j;
	char	**num_char;
	long	num;

	i = 1;
	while (i < argc)
	{
		num_char = ft_split(argv[i], ' ');
		if (!num_char)
			error_and_exit("Error split");
		j = 0;
		while (num_char[j])
		{
			num = atoi_for_proyect(num_char[j]);
			if (num == ERROR)
				error_and_exit_free(num_char, stack);
			if ((ft_has_duplicates(stack, (int)num)) == TRUE)
				error_and_exit_free(num_char, stack);
			create_node_stack(stack, (int)num);
			j++;
		}
		free_array(num_char);
		i++;
	}
}
