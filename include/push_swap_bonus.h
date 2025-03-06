/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:33:52 by brivera           #+#    #+#             */
/*   Updated: 2025/03/05 14:26:54 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libs/libft/libft.h"

# define FALSE			0
# define TRUE			1
# define ERROR			2147483648

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node		*head;
	t_node		*tail;
	int			size;
}	t_stack;

char	**free_array(char **array);
void	error_and_exit(char *message);
void	error_and_exit_free(char **num_char, t_stack *stack);
int		is_space(char c);
int		is_valid_argument(int argc, char **argv);
long	atoi_for_proyect(const char *str);
void	init_stack(t_stack *stack);
t_node	*create_node(int data);
void	push_back(t_stack *stack, t_node *node);
void	free_stack(t_stack *stack);
int		ft_has_duplicates(t_stack *stack, int num);
void	parse_int_from_str(int argc, char **argv, t_stack *stack);
void	execute_mov(char *move, t_stack *a, t_stack *b);
int		control_num_stack_a(t_stack *a);
int		is_valid_argument_a(int argc, char **argv);
int		ft_has_duplicates(t_stack *stack, int num);
void	parse_int_from_str(int argc, char **argv, t_stack *stack);
void	do_sa(t_stack *a);
void	do_sb(t_stack *b);
void	do_rra(t_stack *a);
void	do_rrb(t_stack *b);
void	do_ra(t_stack *a);
void	do_rb(t_stack *b);
void	do_pa(t_stack *a, t_stack *b);
void	do_pb(t_stack *a, t_stack *b);
void	do_rrr(t_stack *a, t_stack *b);
void	do_ss(t_stack *a, t_stack *b);
void	do_rr(t_stack *a, t_stack *b);

#endif