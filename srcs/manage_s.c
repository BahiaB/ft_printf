/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahiabenali <bahiabenali@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:43:48 by bbenali           #+#    #+#             */
/*   Updated: 2021/12/04 22:00:54 by bahiabenali      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	prec_only(t_printf *g)
{
	int i;

	i = 0;
	g->s2 = (char*)malloc(sizeof(char) * g->prec + 1);
	if (g->prec > 0)
	{
		if (*g->s1)
		{
			while (*g->s1 && i < g->prec)
			{
				g->s2[i] = g->s1[i];
				i++;
			}
		}
		g->s2[i] = '\0';
	}
}

void	width_only(t_printf *g)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (g->s_size > g->champ && g->champ > 0)
	{
		s_only(g);
		return ;
	}
	g->s2 = (char*)malloc(sizeof(char) * g->champ + 1);
	while (i + g->s_size < g->champ && g->champ > 0)
	{
		g->s2[i++] = ' ';
	}
	if (*g->s1)
	{
		while (j < g->s_size)
		{
			g->s2[i] = g->s1[j];
			i++;
			j++;
		}
	}
	g->s2[i] = '\0';
}

void	width_min(t_printf *g)
{
	int i;

	i = 0;
	if (g->s_size > g->champ && g->champ > 0)
	{
		s_only(g);
		return ;
	}
	g->s2 = (char*)malloc(sizeof(char) * g->champ + 1);
	if (*g->s1)
	{
		while (g->s1[i] != '\0')
		{
			g->s2[i] = g->s1[i];
			i++;
		}
	}
	while (i < g->champ && g->champ > 0)
	{
		g->s2[i] = ' ';
		i++;
	}
	g->s2[i] = '\0';
}

void	width_prec_min(t_printf *g)
{
	prec_only(g);
	g->s1 = g->s2;
	g->s_size = strlen(g->s1);
	width_min(g);
}

void	width_prec(t_printf *g)
{
	g->s2 = (char*)malloc(sizeof(char) * g->champ + 1);
	prec_only(g);
	g->s1 = g->s2;
	g->s_size = strlen(g->s1);
	width_only(g);
}
