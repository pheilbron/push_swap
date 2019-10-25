/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:45:54 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/25 15:46:10 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ps_stack.h"

t_ps_stack	*ps_stack_init(void)
{
	t_ps_stack	*ret;

	if (!(ret = malloc(sizeof(*ret))))
		return (NULL);
	ret->top = NULL;
	ret->bottom = NULL;
	return (ret);
}
