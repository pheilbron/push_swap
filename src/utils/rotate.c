/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:42:58 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/27 12:56:37 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ps_stack.h"

void	ra(t_ps_stack *a)
{
	int	a_top;

	if (a->size > 1)
		if (ps_stack_pop(a, &a_top))
			ps_stack_enqueue(a, a_top);
}

void	rb(t_ps_stack *b)
{
	int	b_top;

	if (b->size > 1)
		if (ps_stack_pop(b, &b_top))
			ps_stack_enqueue(b, b_top);
}

void	rr(t_ps_stack *a, t_ps_stack *b)
{
	ra(a);
	rb(b);
}
