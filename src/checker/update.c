/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:36:08 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/27 13:04:17 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "utils.h"
#include "ps_stack.h"

static int	execute_command(t_ps_context *c, int cmd)
{
	if (cmd == 's' + 'a')
		sa(c->a);
	else if (cmd == 's' + 'b')
		sb(c->b);
	else if (cmd == 's' + 's')
		ss(c->a, c->b);
	else if (cmd == 'p' + 'a')
		pa(c->a, c->b);
	else if (cmd == 'p' + 'b')
		pb(c->a, c->b);
	else if (cmd == 'u' + 'a')
		ra(c->a);
	else if (cmd == 'u' + 'b')
		rb(c->b);
	else if (cmd == 'u' + 'u')
		rr(c->a, c->b);
	else if (cmd == 'u' + 'u' + 'a')
		rra(c->a);
	else if (cmd == 'u' + 'u' + 'b')
		rrb(c->b);
	else if (cmd == 'u' + 'u' + 'u')
		rrr(c->a, c->b);
	else
		return (0);
	return (1);
}

int			update_stacks(t_ps_context *c)
{
	int	cmd;

	while (!ps_stack_is_empty(c->commands))
		if (ps_stack_pop(c->commands, &cmd))
			if (!execute_command(c, cmd))
				return (0);
	return (1);
}
