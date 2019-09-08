/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:40:19 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/08 13:50:26 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	pa(stack *a, stack *b)
{
	if (!ft_stack_is_empty(b))
		ft_stack_push(a, (int)ft_stack_pop(b));
}

void	pb(stack *a, stack *b)
{
	if (!ft_stack_is_empty(a))
		ft_stack_push(b, (int)ft_stack_pop(a));
}
