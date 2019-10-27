/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:40:19 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/27 12:55:55 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ps_stack.h"

void	pa(t_ps_stack *a, t_ps_stack *b)
{
	int	n;

	if (!ps_stack_is_empty(b))
		if (ps_stack_pop(b, &n))
			ps_stack_push(a, n);
}

void	pb(t_ps_stack *a, t_ps_stack *b)
{
	int	n;

	if (!ps_stack_is_empty(a))
		if (ps_stack_pop(a, &n))
			ps_stack_push(b, n);
}
