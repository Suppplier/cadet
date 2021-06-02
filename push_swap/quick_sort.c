/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:59:26 by jupark            #+#    #+#             */
/*   Updated: 2021/06/02 20:43:15 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		swap(int *ary, int x, int y)
{
	int 	temp;
	
	temp = ary[x];
	ary[x] = ary[y];
	ary[y] = temp;
}

static int		partition(int *ary, int left, int right)
{
	int		pivot;
	int		low;
	int		high;
	
	low = left + 1;
	high = right;
	pivot = ary[left];
	while (low <= high)
	{
		while (low <= right && pivot >= ary[low])
			low++;
		while (high >= (left + 1) && pivot <= ary[high])
			high--;
		if (low <= high)
			swap(ary, low, high);
	}
	swap(ary, left, high);
	return (high);
}

void			ft_quick_sort(int *ary, int left, int right)
{
	int		pivot;

	if (left <= right)
	{
		pivot = partition(ary, left, right);
		ft_quick_sort(ary, left, pivot - 1);
		ft_quick_sort(ary, pivot + 1, right);
	}
}

void			ft_get_pivot(int *ary, int length, int *p1)
{
	ft_quick_sort(ary, 0, length - 1);
	/*
		printf("ary : ");
		for(int i = 0; i < length; i++)
		printf("%d ", ary[i]);
		printf("\n");
	*/
	if (length == 2)
		*p1 = ary[0];
	else
		*p1 = ary[length / 2];
}

void			get_pivot_from_lst(t_stacks *stack, t_list *lst, int size)
{
	t_node	*head;
	int		ary[size];
	int		i;

	head = lst->head;
	i = -1;
	//printf("lst len = %d\n", ft_lstcnt(lst));
	while (++i < size)
	{
		//if (i > 1 && head == lst->head)
		//	break;
		ary[i] = head->num;
		head = head->next;
	}
	ft_get_pivot(ary, size, &(stack->p1));
}
