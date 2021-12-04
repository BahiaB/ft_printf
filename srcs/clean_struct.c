/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahiabenali <bahiabenali@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:40:30 by bbenali           #+#    #+#             */
/*   Updated: 2021/12/04 21:23:58 by bahiabenali      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_clean(t_printf *g)
{
	g->min = 0;
	g->zero = 0;
	g->champ = 0;
	g->prec = 0;
	g->star_champ = 0;
	g->point_prec = 0;
	g->star_prec = 0;
	g->s1 = NULL;
	g->s2 = NULL;
	g->s_size = 0;
	g->s = 0;
	g->i = 0;
	g->c = 0;
	g->d = 0;
	g->u = 0;
	g->p = 0;
	g->x = 0;
	g->m_x = 0;
}

//void	ft_free(t_printf *g)
//{
//	if (g->s1 != NULL)
//		free(g->s1);
//}
