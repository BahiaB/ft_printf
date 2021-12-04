/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahiabenali <bahiabenali@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:43:30 by bbenali           #+#    #+#             */
/*   Updated: 2021/12/04 21:24:24 by bahiabenali      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strrev(char *str)
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

char	*ft_itoa_conv_base_ll(char *str, char neg, long long nu, int base)
{
	int i;

	i = 0;
	while (nu > 0)
	{
		if (nu % base >= 10)
		{
			str[i++] = (nu % base) + 48 + 7 + 32;
			nu = nu / base;
		}
		else
		{
			str[i++] = (nu % base) + 48;
			nu = nu / base;
		}
	}
	if (neg == '-')
	{
		str[i] = neg;
		str[i + 1] = 0;
	}
	else
		str[i] = 0;
	return (str);
}

char	*ft_itoa_base_ll(unsigned long n, int b)
{
	char			*str;
	char			neg;
	long long		nu;

	neg = 0;
	nu = n;
	if (n < 0)
	{
		neg = '-';
		nu = -n;
	}
	str = (char*)malloc(sizeof(char) * 40);
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = 0 + 48;
		str[1] = 0;
		return (str);
	}
	str = ft_itoa_conv_base_ll(str, neg, nu, b);
	str = ft_strrev(str);
	return (ft_strjoin("0x", str));
}
