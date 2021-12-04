/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahiabenali <bahiabenali@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:44:39 by bbenali           #+#    #+#             */
/*   Updated: 2021/12/04 22:01:00 by bahiabenali      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_c(t_printf *g)
{
	if (g->champ == 0)
		c_only(g);
	if (g->champ > 0)
	{
		if (g->min == 0)
			c_width_only(g);
		if (g->min == 1)
			c_width_min(g);
	}
}

void	c_only(t_printf *g)
{
	putchar_count(g->t, g);
}

void	c_width_only(t_printf *g)
{
	int i;

	i = 0;
	g->s2 = (char*)malloc(sizeof(char) * g->champ + 1);
	while (i < g->champ - 1)
	{
		g->s2[i] = ' ';
		i++;
	}
	if (i + 1 == g->champ)
	{
		g->s2[i] = g->t;
	}
	put_struct_s(g);
}

void	c_width_min(t_printf *g)
{
	int i;

	i = 0;
	g->s2 = (char*)malloc(sizeof(char) * g->champ + 1);
	g->s2[i] = g->t;
	i++;
	while (i < g->champ)
	{
		g->s2[i] = ' ';
		i++;
	}
	put_struct_s(g);
}
