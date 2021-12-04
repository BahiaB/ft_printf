/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_s_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahiabenali <bahiabenali@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:42:07 by bbenali           #+#    #+#             */
/*   Updated: 2021/12/04 22:00:55 by bahiabenali      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_s_prec(t_printf *g)
{
	g->s_size = strlen(g->s1);
	if (g->champ == 0)
	{
		if (g->prec == 0)
			s_only(g);
		if (g->prec > 0)
			prec_only(g);
	}
	check_s_champ(g);
	put_struct_s(g);
}

void	check_s_champ(t_printf *g)
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
				width_prec(g);
			if (g->min == 1)
				width_prec_min(g);
			if (g->zero == 1)
				width_zero(g);
		}
	}
}

void	s_only(t_printf *g)
{
	g->s2 = g->s1;
	//printf("s_only  = %s\n", g->s2);
}

void	put_struct_s(t_printf *g)
{
	if (g->s2)
	{
		while (*g->s2 != '\0')
		{
			putchar_count(*g->s2, g);
			g->s2++;
		}
	}
}

void	width_zero(t_printf *g)
{
	int i;

	i = 0;
	width_only(g);
	g->s1 = g->s2;
	while (g->s1[i] == ' ')
	{
		g->s2[i] = '0';
		i++;
	}
}
