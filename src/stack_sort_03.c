/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:58:14 by brivera@stu       #+#    #+#             */
/*   Updated: 2025/03/03 14:08:09 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	insertion_sort(int *arr, int left, int right)
{
	int	i;
	int	j;
	int	temp;

	i = left + 1;
	while (i <= right)
	{
		temp = arr[i];
		j = i - 1;
		while (j >= left && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
		i++;
	}
}

static t_merge	prepare_merge_data(int *arr, int l, int r, int m)
{
	t_merge	data;
	int		i;

	data.left_size = m - l + 1;
	data.right_size = r - m;
	data.left = (int *)ft_calloc(data.left_size, sizeof(int));
	data.right = (int *)ft_calloc(data.right_size, sizeof(int));
	if (!data.left || !data.right)
		error_and_exit("Error ft_calloc");
	i = 0;
	while (i < data.left_size)
	{
		data.left[i] = arr[l + i];
		i++;
	}
	i = 0;
	while (i < data.right_size)
	{
		data.right[i] = arr[m + 1 + i];
		i++;
	}
	data.i = 0;
	data.j = 0;
	data.k = l;
	return (data);
}

static void	marge_phase_one(t_merge *data, int arr[])
{
	while (data->i < data->left_size && data->j < data->right_size)
	{
		if (data->left[data->i] <= data->right[data->j])
		{
			arr[data->k] = data->left[data->i];
			data->i++;
		}
		else
		{
			arr[data->k] = data->right[data->j];
			data->j++;
		}
		data->k++;
	}
}

void	merge(int *arr, int l, int r, int m)
{
	t_merge	data;

	data = prepare_merge_data(arr, l, r, m);
	marge_phase_one(&data, arr);
	while (data.i < data.left_size)
	{
		arr[data.k] = data.left[data.i];
		data.i++;
		data.k++;
	}
	while (data.j < data.right_size)
	{
		arr[data.k] = data.right[data.j];
		data.j++;
		data.k++;
	}
	free(data.left);
	free(data.right);
}

/*
static void	phase_one(int *arr, int n)
{
	int	i;
	int	right;

	i = 0;
	while (i < n)
	{
		right = i + RUN - 1;
		if (right >= n)
			right = n - 1;
		insertion_sort(arr, i, right);
		i = i + RUN;
	}
}

static void	phase_two(int *arr, int n)
{
	int	right;
	int	size;
	int	left;
	int	mid;

	size = RUN;
	while (size < n)
	{
		left = 0;
		while (left < n)
		{
			mid = left + size - 1;
			right = left + 2 * size - 1;
			if (right >= n)
				right = n - 1;
			if (mid < right)
				merge(arr, left, right, mid);
			left += 2 * size;
		}
		size *= 2;
	}
}

void	timsort(int *arr, int n)
{
	phase_one(arr, n);
	phase_two(arr, n);
}

void	print_array(int *arr, int n)
{
	int i;
	i = 0;
	while (i < n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

int	main(void)
{
	int *arr = {5, 21, 7, 23, 19, 2, 13, 11, 3, 17, -2, 3, 45, 34, -4444, 5};
	int n;

	n = sizeof(arr) / sizeof(arr[0]);
	printf("Array original: ");
	print_array(arr, n);
	timsort(arr, n);
	printf("Array ordenado: ");
	print_array(arr, n);
	return (0);
}
*/