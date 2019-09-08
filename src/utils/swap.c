/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 12:58:42 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/08 13:55:10 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_stack.h"
#include "utils.h"

void	sa(t_stack *a)
{
	int	top;
	int	second;

	if (a->size > 1)
	{
		top = (int)ft_stack_pop(a);
		second = (int)ft_stack_pop(a);
		ft_stack_push(a, top);
		ft_stack_push(a, second);
	}
}

void	sb(t_stack *b)
{
	int	top;
	int	second;

	if (b->size > 1)
	{
		top = (int)ft_stack_pop(b);
		second = (int)ft_stack_pop(b);
		ft_stack_push(b, top);
		ft_stack_push(b, second);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
