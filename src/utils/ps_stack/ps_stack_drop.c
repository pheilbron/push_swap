/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_drop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:43:29 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/25 15:54:08 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ps_stack.h"

int	ps_stack_drop(t_ps_stack *stack)
{
	t_ps_node	*temp;
	void		*content;

	if (ps_stack_is_empty(stack))
		return (NULL);
	content = stack->bottom->content;
	temp = stack->bottom;
	stack->bottom = temp->prev;
	if (!(stack->bottom))
		stack->top = NULL;
	free(temp);
	return (content);
}
