/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_context.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:09:08 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/08 14:09:12 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CONTEXT_H
# define PS_CONTEXT_H

typedef struct	s_ps_context
{
	uint8_t	options;
	t_stack	*a;
	t_stack	*b;
}				t_ps_context;

#endif
