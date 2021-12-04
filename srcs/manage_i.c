/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahiabenali <bahiabenali@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:41:12 by bbenali           #+#    #+#             */
/*   Updated: 2021/12/04 22:00:56 by bahiabenali      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	prec_i(t_printf *g)
{
	if (g->prec <= g->s_size)
	{
		s_only(g);
		return ;
	}
	if (*g->s1 && g->prec > g->s_size)
		prec_i_cp(g);
	ft_add_min(g);
}

void	prec_i_cp(t_printf *g)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (*g->s1 && g->prec > g->s_size)
	{
		g->s2 = (char*)malloc(sizeof(char) * g->prec + 1);
		while (i + g->s_size < g->prec)
			g->s2[i++] = '0';
		while (i < g->prec)
		{
			if (g->s1[j] == '-')
			{
				g->s2[0] = '0';
				g->s1[j] = '0';
				g->t = 1;
			}
			g->s2[i] = g->s1[j];
			i++;
			j++;
		}
	}
	g->s2[i] = '\0';
}

void	ft_add_min(t_printf *g)
{
	int i;

	i = 0;
	if (g->s1[0] == '0')
	{
		g->s3 = (char*)malloc(sizeof(char) * strlen(g->s2) + 1);
		g->s3[i] = '-';
		i++;
		while (*g->s2 && *g->s2 != '\0')
		{
			g->s3[i] = *g->s2;
			i++;
			g->s2++;
		}
		g->s3[i] = '\0';
		g->s2 = g->s3;
		free(g->s3);
	}
	else
		return ;
}

void	width_prec_i(t_printf *g)
{
	g->s2 = (char*)malloc(sizeof(char) * g->champ + 1);
	prec_i(g);
	g->s1 = g->s2;
	g->s_size = strlen(g->s1);
	width_only(g);
}

void	width_prec_min_i(t_printf *g)
{
	g->s2 = (char*)malloc(sizeof(char) * g->champ + 1);
	prec_i(g);
	g->s1 = g->s2;
	g->s_size = strlen(g->s1);
	width_min(g);
}
