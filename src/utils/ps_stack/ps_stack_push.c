/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:47:26 by pheilbro          #+#    #+#             */
/*   Updated: 2019/11/03 12:32:55 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ps_stack.h"

int	ps_stack_push(t_ps_stack *stack, int content)
{
	t_ps_node	*new;

	if ((new = malloc(sizeof(*new))))
	{
		new->content = content;
		new->prev = NULL;
		if (!ps_stack_is_empty(stack))
		{
			stack->top->prev = new;
			new->next = stack->top;
		}
		else
		{
			new->next = NULL;
			stack->bottom = new;
		}
		stack->top = new;
		stack->size++;
	}
	return (content);
}
