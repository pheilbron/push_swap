/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:36:08 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/24 13:01:18 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		get_cmd(char *command);
{
	int	cmd;
	int	i;

	cmd = 0;
	i = -1;
	while (command[++i])
		cmd += command[i] == 'r' ? 'u' : command[i];
	free(command);
	return (cmd);
}

void	execute_command(t_ps_context *c, int cmd)
{
	if (cmd == 's' + 'a')
		sa(c->a);
	else if (cmd == 's' + 'b')
		sb(c->b);
	else if (cmd == 's' + 's')
		ss(c->a, c->b);
	else if (cmd == 'p' + 'a')
		pa(c->a);
	else if (cmd == 'p' + 'b')
		pb(c->b);
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
}

void	update_stacks(t_ps_context *c)
{
	while (!ft_stack_is_empty(c->commands))
		execute_command(c, get_cmd(ft_stack_pop(c->commands)));
}
