/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:47:19 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/27 12:25:39 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "ps_stack.h"

void	sa(t_ps_stack *a);
void	sb(t_ps_stack *b);
void	ss(t_ps_stack *a, t_ps_stack *b);
void	pa(t_ps_stack *a, t_ps_stack *b);
void	pb(t_ps_stack *a, t_ps_stack *b);
void	ra(t_ps_stack *a);
void	rb(t_ps_stack *b);
void	rr(t_ps_stack *a, t_ps_stack *b);
void	rra(t_ps_stack *a);
void	rrb(t_ps_stack *b);
void	rrr(t_ps_stack *a, t_ps_stack *b);

#endif
