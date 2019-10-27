/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:42:48 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/27 12:52:31 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ps_stack.h"

void	ps_stack_del(t_ps_stack *stack)
{
	t_ps_node	*n;
	t_ps_node	*prev;

	n = stack->bottom;
	prev = ps_stack_get_prev(n);
	while (n)
	{
		free(n);
		n = prev;
		prev = ps_stack_get_prev(prev);
	}
	free(stack);
}
