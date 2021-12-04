/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahiabenali <bahiabenali@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:42:16 by bbenali           #+#    #+#             */
/*   Updated: 2021/12/04 21:24:14 by bahiabenali      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_type_c_s(char *str, t_printf *g, va_list ap)
{
	if (*str == 'c')
	{
		g->c = 1;
		g->t = va_arg(ap, int);
		printf("g->c = %d\n", g->c);
	}
	if (*str == 's')
	{
		g->s = 1;
		g->s1 = va_arg(ap, char*);
		//printf("g->s = %d\n", g->s);
	}
	init_type_int(str, g, ap);
}

void	init_type_int(char *str, t_printf *g, va_list ap)
{
	if ((*str == 'i') || (*str == 'd'))
	{
		g->i = 1;
		g->i2 = va_arg(ap, int);
		g->s1 = itoa(g->i2);
	}
	if (*str == 'u')
	{
		g->u = 1;
		g->un_i = va_arg(ap, unsigned int);
		g->s1 = itoa_long(g->un_i);
	}
	if ((*str == 'x') || (*str == 'X'))
	{
		if (*str == 'x')
			g->x = 1;
		if (*str == 'X')
			g->m_x = 1;
		g->un_i = va_arg(ap, unsigned int);
		g->s1 = ft_itoa_base_long(g->un_i, 16, g);
	}
	init_type_p(str, g, ap);
	str++;
	g->save = str;
}

void	init_type_p(char *str, t_printf *g, va_list ap)
{
	if (*str == 'p')
	{
		g->p = 1;
		g->un_l = va_arg(ap, unsigned long);
		g->s1 = ft_itoa_base_ll(g->un_l, 16);
	}
}
