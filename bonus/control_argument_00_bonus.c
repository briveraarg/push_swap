/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_argument_00_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:28:11 by brivera           #+#    #+#             */
/*   Updated: 2025/03/05 14:28:17 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static int	ft_isnumber(const char *str)
{
	size_t	i;

	i = 0;
	if (ft_strlen(str) == 1)
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
	}
	if (!str || !str[i])
		return (FALSE);
	if (str[i] == '+' || str[i] == '-')
		str++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	is_not_empty(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (FALSE);
	while (str[i])
	{
		if (is_space(str[i]))
			i++;
		else
			break ;
	}
	if (str[i] == '\0')
		return (FALSE);
	return (TRUE);
}

int	is_valid_argument_a(int argc, char **argv)
{
	int			i;
	char		**array;
	size_t		j;

	i = 1;
	while (i < argc)
	{
		if (!is_not_empty(argv[i]))
			return (FALSE);
		array = ft_split(argv[i], ' ');
		if (!array)
			return (FALSE);
		j = 0;
		while (array[j])
		{
			if (!ft_isnumber(array[j]))
				return (free_array(array), FALSE);
			j++;
		}
		free_array(array);
		i++;
	}
	return (TRUE);
}

int	control_num_stack_a(t_stack *a)
{
	t_node	*current;

	if (a->size == 0 || a->size == 1)
		return (TRUE);
	current = a->head;
	while (current && current->next)
	{
		if (current->data > current->next->data)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}
