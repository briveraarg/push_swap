/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:33:41 by brivera           #+#    #+#             */
/*   Updated: 2025/03/05 14:20:51 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static void	free_stacks_exit(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	error_and_exit("Error");
}

void	execute_mov(char *move, t_stack *a, t_stack *b)
{
	if (ft_strncmp(move, "sa\n", 3) == 0)
		do_sa(a);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		do_sb(b);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		do_ss(a, b);
	else if (ft_strncmp(move, "pa\n", 3) == 0)
		do_pa(a, b);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		do_pb(a, b);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		do_ra(a);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		do_rb(b);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		do_rr(a, b);
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		do_rra(a);
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		do_rrb(b);
	else if (ft_strncmp(move, "rrr\n", 4) == 0)
		do_rrr(a, b);
	else
		free_stacks_exit(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*move;

	if (argc == 1)
		return (0);
	if (!is_valid_argument_a(argc, argv))
		error_and_exit("Error");
	init_stack(&a);
	init_stack(&b);
	parse_int_from_str(argc, argv, &a);
	move = get_next_line(0);
	while (move)
	{
		execute_mov(move, &a, &b);
		free(move);
		move = get_next_line(0);
	}
	if (control_num_stack_a(&a) == TRUE && b.size == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 2);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
