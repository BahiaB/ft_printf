/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_et_itoa_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahiabenali <bahiabenali@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:42:34 by bbenali           #+#    #+#             */
/*   Updated: 2021/12/04 22:15:39 by bahiabenali      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_printf.h"



char		*ft_itoa_conv(char *str, char neg, unsigned int nu)
{
	int i;

	i = 0;
	while (nu > 0)
	{
		str[i] = (nu % 10) + 48;
		nu = nu / 10;
		i++;
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

char		*itoa(int n)
{
	char			*str;
	char			neg;
	unsigned int	nu;

	neg = 0;
	nu = n;
	if (n < 0)
	{
		neg = '-';
		nu = -n;
	}
	str = (char*)malloc(sizeof(char) * 12);
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = 0 + 48;
		str[1] = 0;
		return (str);
	}
	str = ft_itoa_conv(str, neg, nu);
	return (ft_strrev(str));
}

char		*itoa_long(long int n)
{
	char			*str;
	char			neg;
	unsigned int	nu;

	neg = 0;
	nu = n;
	if (n < 0)
	{
		neg = '-';
		nu = -n;
	}
	str = (char*)malloc(sizeof(char) * 12);
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = 0 + 48;
		str[1] = 0;
		return (str);
	}
	str = ft_itoa_conv(str, neg, nu);
	return (ft_strrev(str));
}
