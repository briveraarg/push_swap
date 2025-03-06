/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:36:04 by brivera@stu       #+#    #+#             */
/*   Updated: 2025/03/04 14:14:22 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"

# define FALSE			0
# define TRUE			1
# define NEAR_SORTED	2
# define ERROR			2147483648

# define RUN			32

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
	int				index;
}	t_node;

typedef struct s_stack
{
	t_node		*head;
	t_node		*tail;
	int			size;
}	t_stack;

typedef struct s_merge
{
	int	*left;
	int	*right;
	int	left_size;
	int	right_size;
	int	i;
	int	j;
	int	k;
}	t_merge;

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
void	sa(t_stack *a, int stdin);
void	sb(t_stack *b, int stdin);
void	ss(t_stack *a, t_stack *b, int stdin);
void	pa(t_stack *a, t_stack *b, int stdin);
void	pb(t_stack *a, t_stack *b, int stdin);
void	ra(t_stack *a, int stdin);
void	rb(t_stack *b, int stdin);
void	rr(t_stack *a, t_stack *b, int stdin);
void	rra(t_stack *a, int stdin);
void	rrb(t_stack *b, int stdin);
void	rrr(t_stack *a, t_stack *b, int stdin);
int		control_num_stack(t_stack *stack);
void	insertion_sort(int *arr, int left, int right);
void	merge(int *arr, int l, int r, int m);
void	stack_sort_three(t_stack *stack);
void	stack_sort_four(t_stack *stack_a, t_stack *stack_b);
void	stack_sort_five_and_eight(t_stack *stack_a, t_stack *stack_b, int lim);
void	load_index_whit_timsort(t_stack *stack_a);
void	stack_sort_major_league(t_stack *stack_a, t_stack *stack_b);
void	stack_sort(t_stack *stack_a);
#endif

//void 	imprimie_stack(t_stack *s);