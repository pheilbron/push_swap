/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_enqueue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:44:51 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/28 13:25:44 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ps_stack.h"

void	ps_stack_enqueue(t_ps_stack *stack, int content)
{
	t_ps_node	*new;

	if ((new = malloc(sizeof(*new))))
	{
		new->content = content;
		new->next = NULL;
		if (ps_stack_is_empty(stack))
		{
			stack->top = new;
			new->prev = NULL;
		}
		else
		{
			stack->bottom->next = new;
			new->prev = stack->bottom;
		}
		stack->bottom = new;
		stack->size++;
	}
}
