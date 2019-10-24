/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_context.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:09:08 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/24 14:14:31 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CONTEXT_H
# define PS_CONTEXT_H

typedef struct	s_ps_context
{
	uint8_t	options;
	t_stack	*a;
	t_stack	*b;
	t_stack	*commands;
}				t_ps_context;

int		init_ps_context(void);
void	*free_ps_context(t_ps_context *c);

#endif
