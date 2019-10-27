/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:45:29 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/27 12:58:32 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ps_stack.h"

void	rra(t_ps_stack *a)
{
	int	n;

	if (!ps_stack_is_empty(a))
		if (ps_stack_drop(a, &n))
			ps_stack_push(a, n);
}

void	rrb(t_ps_stack *b)
{
	int	n;

	if (!ps_stack_is_empty(b))
		if (ps_stack_drop(b, &n))
			ps_stack_push(b, n);
}

void	rrr(t_ps_stack *a, t_ps_stack *b)
{
	rra(a);
	rrb(b);
}
