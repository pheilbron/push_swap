/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:42:48 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/28 10:27:27 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ps_stack.h"

void	ps_stack_del(t_ps_stack *stack)
{
	t_ps_node	*n;

	while (stack->bottom != stack->top)
	{
		n = stack->bottom;
		stack->bottom = stack->bottom->prev;
		stack->bottom->next = NULL;
		free(n);
		n = NULL;
	}
	free(stack);
}
