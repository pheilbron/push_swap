/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:42:58 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/08 13:45:20 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ra(t_stack *a)
{
	int	a_top;

	if (a->size > 1)
	{
		a_top = (int)ft_stack_pop(a);
		if (a_top)
			ft_stack_enqueue(a, a_top);
	}
}

void	rb(t_stack *b)
{
	int	b_top;

	if (b->size > 1)
	{
		b_top = (int)ft_stack_pop(b);
		if (b_top)
			ft_stack_enqueue(b, b_top);
	}
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
