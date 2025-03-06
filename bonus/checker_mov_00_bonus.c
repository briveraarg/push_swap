/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_mov_00_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:11:55 by brivera           #+#    #+#             */
/*   Updated: 2025/03/04 17:54:23 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	do_rrr(t_stack *a, t_stack *b)
{
	do_rra(a);
	do_rrb(b);
}

void	do_ss(t_stack *a, t_stack *b)
{
	do_sa(a);
	do_sb(b);
}

void	do_rr(t_stack *a, t_stack *b)
{
	do_ra(a);
	do_rb(b);
}
