/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:42:48 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/25 15:43:23 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ps_stack.h"

void	ps_stack_del(t_ps_stack *stack)
{
	while (!ps_stack_is_empty(stack))
		free(ps_stack_pop(stack));
	free(stack);
}
