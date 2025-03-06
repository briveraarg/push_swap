/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:28:40 by brivera           #+#    #+#             */
/*   Updated: 2025/03/05 14:28:47 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	error_and_exit(char *message)
{
	ft_putendl_fd(message, 2);
	exit(255);
}

void	error_and_exit_free(char **num_char, t_stack *stack)
{
	free_array(num_char);
	free_stack(stack);
	error_and_exit("Error");
}

char	**free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

long	atoi_for_proyect(const char *str)
{
	long	num;
	int		sig;
	size_t	i;

	num = 0;
	sig = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while ((ft_isdigit(str[i])))
	{
		num = num * 10 + (str[i] - '0');
		if ((sig == 1 && num > INT_MAX) || (sig == -1 && (-num) < INT_MIN))
			return (ERROR);
		i++;
	}
	return ((int)(num * sig));
}
