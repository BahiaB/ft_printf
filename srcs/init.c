/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahiabenali <bahiabenali@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:40:42 by bbenali           #+#    #+#             */
/*   Updated: 2021/12/04 21:24:18 by bahiabenali      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init(char *str, t_printf *g, va_list ap)
{
	init_flag(str, g, ap);
	if (g->champ == 0 && g->star_champ > 0)
		g->champ = g->star_champ;
	if (g->prec == 0 && g->star_prec > 0)
		g->prec = g->star_prec;
	check_type(g);
}

void	check_type(t_printf *g)
{
	if (g->s == 1)
	{
		check_s_prec(g);
	}
	if (g->c == 1)
	{
		check_c(g);
	}
	if ((g->i == 1) || (g->d == 1) || (g->u == 1))
	{
		check_i_prec(g);
	}
	if ((g->x == 1) || (g->m_x == 1) || (g->p == 1))
	{
		check_i_prec(g);
	}
}

void	init_flag(char *str, t_printf *g, va_list ap)
{
	while (*str == '0' || *str == '-')
	{
		if (*str == '0')
			g->zero = 1;
		if (*str == '-')
			g->min = 1;
		str++;
	}
	if (g->min == 1)
		g->zero = 0;
	init_width(str, g, ap);
	//printf("g->min = %d g->zero = %d\n", g->min, g->zero);
}

void	init_width(char *str, t_printf *g, va_list ap)
{
	if (*str >= '0' && *str <= '9')
		g->champ = atoi(str);
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str == '*')
	{
		g->star_champ = 1;
		g->champ = va_arg(ap, int);
		str++;
	}
	init_prec(str, g, ap);
	//printf("g->champ = %d g->star_champ = %d\n", g->champ, g->star_champ);
}

void	init_prec(char *str, t_printf *g, va_list ap)
{
	if (*str == '.')
	{
		str++;
		if (*str >= '0' && *str <= '9')
		{
			g->prec = atoi(str);
			while (*str >= '0' && *str <= '9')
				str++;
		}
		if (*str == '*')
		{
			g->star_prec = 1;
			g->prec = va_arg(ap, int);
			str++;
		}
	}
	init_type_c_s(str, g, ap);
	//printf("g->prec = %d g->star_prec = %d\n", g->prec, g->star_prec);
}
