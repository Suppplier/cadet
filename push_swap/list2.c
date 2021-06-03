/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:16:44 by jupark            #+#    #+#             */
/*   Updated: 2021/06/03 17:27:10 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_num_swap(t_node *n1, t_node *n2)
{
	int		temp;
	
	temp = n1->num;
	n1->num = n2->num;
	n2->num = temp;
}

void	ft_stackcnt_init(t_stacks *stack)
{
	stack->r_cnt = 0;
	stack->p_cnt = 0;
}

void	ft_lstdelone(t_node *node)
{
	if(!node)
		return ;
	free(node);
}

void	ft_lstclear(t_list *lst)
{
	t_node *current_n;
	t_node *next_n;

	if(!lst)
		return ;
	current_n = lst->head;
	while(current_n)
	{
		next_n = current_n->next;
		ft_lstdelone(current_n);
		current_n = next_n;
	}
	free(lst);
}
