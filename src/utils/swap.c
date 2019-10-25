/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 12:58:42 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/24 20:40:39 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_stack.h"

void	sa(t_stack *a)
{
	void	*top;
	void	*second;

	if (a->size > 1)
	{
		top = ft_stack_pop(a);
		second = ft_stack_pop(a);
		ft_stack_push(a, top);
		ft_stack_push(a, second);
	}
}

void	sb(t_stack *b)
{
	void	*top;
	void	*second;

	if (b->size > 1)
	{
		top = ft_stack_pop(b);
		second = ft_stack_pop(b);
		ft_stack_push(b, top);
		ft_stack_push(b, second);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
