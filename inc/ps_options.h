/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_options.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:01:20 by pheilbro          #+#    #+#             */
/*   Updated: 2019/10/24 20:14:54 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_OPTIONS_H
# define PS_OPTIONS_H

# define _C 1
# define _D 2
# define _I 4
# define _O 8
# define _V 16
# define _X 32
# define SLOW 18

# define SORTED 64

# define INV_ARG -1

typedef struct	s_ps_option
{
	uint8_t	flag;
	char	op;
	char	*long_op;
}				t_ps_option;

extern t_ps_option	g_option_tab[];

#endif
