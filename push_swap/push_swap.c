/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:56:01 by jupark            #+#    #+#             */
/*   Updated: 2021/06/03 20:09:52 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_by_cnt(t_stacks *stack, int len, int st)
{
	int		i;

	i = -1;
	if (st)
		while (++i < len)
			ft_rra(stack);
	else
		while (++i < len)
			ft_rrb(stack);
}

void	a_to_b(t_stacks *stack, int size)
{
	t_node	*head;
	int		tmp;
	if (is_sorted(stack->lst_a))
		return ;
	if (size <= 3)
	{
		if (size == 2)
			sort_two(stack, stack->lst_a, 1);
		else if (size == 3)
			sort_three(stack, stack->lst_a, 1);
		return ;
	}
	get_pivot_from_lst(stack, stack->lst_a, size);
	head = stack->lst_a->head;
	while (size--)
	{
		if (head->num > stack->p1)
			ft_ra(stack);
		else
			ft_pb(stack);
		head = stack->lst_a->head;
	}
	rr_by_cnt(stack, stack->r_cnt, 1);
	tmp = stack->p_cnt;
	a_to_b(stack, stack->r_cnt);
	b_to_a(stack, tmp);
}

void	b_to_a(t_stacks *stack, int size)
{
	t_node	*head;
	int		tmp;

	if (size <= 3)
	{
		if (size == 2)
			sort_two(stack, stack->lst_b, 0);
		else if (size == 3)
			sort_three(stack, stack->lst_b, 0);
		while (size--)
			ft_pa(stack);
		return ;
	}
	get_pivot_from_lst(stack, stack->lst_b, size);
	head = stack->lst_b->head;
	while (size--)
	{
		if (head->num <= stack->p1)
			ft_rb(stack);
		else
			ft_pa(stack);
		head = stack->lst_b->head;
	}
	rr_by_cnt(stack, stack->r_cnt, 0);
	tmp = stack->r_cnt;
	a_to_b(stack, stack->p_cnt);
	b_to_a(stack, tmp);
}
