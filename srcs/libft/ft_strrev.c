/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenali <bbenali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:52:21 by bbenali           #+#    #+#             */
/*   Updated: 2019/10/29 18:35:16 by bbenali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strrev(char *str)
{
	int		s;
	int		e;
	char	stock;

	s = 0;
	e = 0;
	while (str[e])
		e++;
	e--;
	while (s < e)
	{
		stock = str[e];
		str[e] = str[s];
		str[s] = stock;
		e--;
		s++;
	}
	return (str);
}
