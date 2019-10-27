/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 12:58:42 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/27 12:59:52 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ps_stack.h"

void	sa(t_ps_stack *a)
{
	int	top;
	int	second;

	if (a->size > 1)
		if (ps_stack_pop(a, &top) && ps_stack_pop(a, &second))
		{
			ps_stack_push(a, top);
			ps_stack_push(a, second);
		}
}

void	sb(t_ps_stack *b)
{
	int	top;
	int	second;

	if (b->size > 1)
		if (ps_stack_pop(b, &top) && ps_stack_pop(b, &second))
		{
			ps_stack_push(b, top);
			ps_stack_push(b, second);
		}
}

void	ss(t_ps_stack *a, t_ps_stack *b)
{
	sa(a);
	sb(b);
}
