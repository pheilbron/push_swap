/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:08:10 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/23 21:20:05 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_stacks(t_ps_context *c)
{
	t_dl_node	*cur;
	t_dl_node	*prev;

	prev = c->a->top;
	while ((cur = ft_stack_get_next(c->a->top)))
	{
		if ((int)cur->content > (int)prev->content)
			return (0);
		prev = cur;
		cur = ft_stack_get_next(cur);
	}
	if (ft_stack_is_empty(c->b))
		return (SORTED);
	return (0);
}
