/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:08:10 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/27 12:06:13 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ps_options.h"
#include "ps_stack.h"
#include "ft_node.h"

int	check_stacks(t_ps_context *c)
{
	t_ps_node	*cur;
	t_ps_node	*prev;

	prev = c->a->top;
	while ((cur = ps_stack_get_next(c->a->top)))
	{
		if (cur->content > prev->content)
			return (0);
		prev = cur;
		cur = ps_stack_get_next(cur);
	}
	if (ps_stack_is_empty(c->b))
		return (SORTED);
	return (0);
}
