/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_i_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahiabenali <bahiabenali@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:40:53 by bbenali           #+#    #+#             */
/*   Updated: 2021/12/04 22:00:58 by bahiabenali      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_i_prec(t_printf *g)
{
	g->s_size = strlen(g->s1);
	if (g->champ == 0)
	{
		if (g->prec == 0)
			s_only(g);
		if (g->prec > 0)
			prec_i(g);
	}
	check_i_champ(g);
	put_struct_s(g);
}

void	check_i_champ(t_printf *g)
{
	if (g->champ > 0)
	{
		if (g->prec == 0)
		{
			if (g->min == 0)
				width_only(g);
			if (g->min == 1)
				width_min(g);
			if (g->zero == 1)
				width_zero(g);
		}
		if (g->prec > 0)
		{
			if (g->min == 0)
				width_prec_i(g);
			if (g->min > 0)
				width_prec_min_i(g);
		}
	}
}
