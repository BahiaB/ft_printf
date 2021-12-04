/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahiabenali <bahiabenali@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:41:23 by bbenali           #+#    #+#             */
/*   Updated: 2021/12/04 21:24:28 by bahiabenali      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa_conv_base(char *str, char neg, int nu, int base)
{
	int i;

	i = 0;
	while (nu > 0)
	{
		if (nu % base >= 10)
		{
			str[i] = (nu % base) + 48 + 7 + 32;
			nu = nu / base;
			i++;
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

char	*ft_itoa_base(int n, int b)
{
	char	*str;
	char	neg;
	int		nu;

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
	str = ft_itoa_conv_base(str, neg, nu, b);
	return (ft_strrev(str));
}

char	*ft_itoa_conv_base_long(char *str, char neg, unsigned int nu, int base)
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
			str[i] = (nu % base) + 48;
			nu = nu / base;
			i++;
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

char	*ft_itoa_base_long(unsigned int n, int b, t_printf *g)
{
	char	*str;
	char	neg;
	int		nu;

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
	str = ft_itoa_conv_base_long(str, neg, nu, b);
	if (g->m_x == 1)
		str = ft_capitalize(str, g);
	return (ft_strrev(str));
}

char	*ft_capitalize(char *str, t_printf *g)
{
	int i;

	i = 0;
	if (g->m_x == 0)
		return (str);
	else if (g->m_x == 1)
	{
		while (str[i] && str[i] != '\0')
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
			i++;
		}
	}
	//printf("capitalize = %s\n",str);
	return (str);
}
