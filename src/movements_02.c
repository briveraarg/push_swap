/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:32:36 by brivera@stu       #+#    #+#             */
/*   Updated: 2025/03/03 15:50:39 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rrr(t_stack *a, t_stack *b, int stdin)
{
	rra(a, FALSE);
	rrb(b, FALSE);
	if (stdin)
		ft_putendl_fd("rrr", 1);
}

void	ss(t_stack *a, t_stack *b, int stdin)
{
	sa(a, FALSE);
	sb(b, FALSE);
	if (stdin)
		ft_putendl_fd("ss", 1);
}

void	rr(t_stack *a, t_stack *b, int stdin)
{
	ra(a, FALSE);
	rb(b, FALSE);
	if (stdin)
		ft_putendl_fd("rr", 1);
}
