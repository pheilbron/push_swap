/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_peek.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:46:40 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/25 15:52:56 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ps_stack.h"

int	ps_stack_peek(t_ps_stack *stack)
{
	if (ps_stack_is_empty(stack))
		return (NULL);
	return (stack->top->content);
}
