/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_contains.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 13:20:39 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/27 13:21:45 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

int	ps_stack_contains(t_ps_stack *stack, int n)
{
	t_ps_node	*node;

	node = stack->top;
	while (node)
	{
		if (node->content == n)
			return (1);
		node = node->next;
	}
	return (0);
}
