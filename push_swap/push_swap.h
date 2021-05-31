/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:03:21 by jupark            #+#    #+#             */
/*   Updated: 2021/06/01 00:28:13 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define NOTENOUGHARG "NOT ENOUGH ARG\n"

typedef struct		s_node
{
	int				num;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct		s_list
{
	t_node			*head;
	t_node			*tail;
}					t_list;

size_t				ft_strlen(char *str);
void				ft_putstr(char *str);
int					ft_atoi(const char *nptr);

t_node				*ft_nodenew(int num);
t_list				*ft_lstnew();
void				ft_lstadd_back(t_list *lst, t_node *new_n);
void				ft_lstadd_front(t_list *lst, t_node *new_n);

void				ft_listdelone(t_node *node);
void				ft_lstclear(t_list *lst);

void				ft_printlst_front(t_list *lst);
void				ft_printlst_back(t_list *lst);

void				ft_swap(t_list *lst);
void				ft_move(t_list *lst, int dir);
void				ft_push(t_list *lst1, t_list *lst2);
#endif