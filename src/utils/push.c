/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:40:19 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/24 20:37:43 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_stack.h"

void	pa(t_stack *a, t_stack *b)
{
	if (!ft_stack_is_empty(b))
		ft_stack_push(a, ft_stack_pop(b));
}

void	pb(t_stack *a, t_stack *b)
{
	if (!ft_stack_is_empty(a))
		ft_stack_push(b, ft_stack_pop(a));
}
