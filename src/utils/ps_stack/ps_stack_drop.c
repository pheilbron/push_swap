/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_drop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:43:29 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/28 13:26:01 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ps_stack.h"

int	ps_stack_drop(t_ps_stack *stack, int *n)
{
	t_ps_node	*temp;

	if (ps_stack_is_empty(stack))
		return (0);
	*n = stack->bottom->content;
	temp = stack->bottom;
	stack->bottom = temp->prev;
	if (!(stack->bottom))
		stack->top = NULL;
	free(temp);
	stack->size--;
	return (1);
}
