/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:47:04 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/27 12:47:34 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ps_stack.h"

int	ps_stack_pop(t_ps_stack *stack, int *n)
{
	t_ps_node	*temp;

	if (ps_stack_is_empty(stack))
		return (0);
	*n = stack->top->content;
	temp = stack->top;
	stack->top = temp->next;
	if (stack->top)
		temp->next->prev = NULL;
	else
		stack->bottom = NULL;
	free(temp);
	return (1);
}
