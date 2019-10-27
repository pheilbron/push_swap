/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_peek.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:46:40 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/27 12:48:32 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ps_stack.h"

int	ps_stack_peek(t_ps_stack *stack, int *n)
{
	if (ps_stack_is_empty(stack))
		return (0);
	*n = stack->top->content;
	return (1);
}
