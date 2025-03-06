/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:01:12 by brivera@stu       #+#    #+#             */
/*   Updated: 2025/03/04 16:18:41 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;

	if (argc == 1)
		return (0);
	if (!is_valid_argument(argc, argv))
		error_and_exit("Error");
	init_stack(&stack_a);
	parse_int_from_str(argc, argv, &stack_a);
	stack_sort(&stack_a);
	free_stack(&stack_a);
	return (0);
}
