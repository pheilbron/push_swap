/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:45:29 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/24 20:38:23 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_stack.h"

void	rra(t_stack *a)
{
	if (!ft_stack_is_empty(a))
		ft_stack_push(a, ft_stack_drop(a));
}

void	rrb(t_stack *b)
{
	if (!ft_stack_is_empty(b))
		ft_stack_push(b, ft_stack_drop(b));
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
