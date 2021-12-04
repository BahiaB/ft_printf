/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenali <bbenali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:52:44 by bbenali           #+#    #+#             */
/*   Updated: 2019/11/04 16:37:17 by bbenali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	check_char(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		j;
	int		i;
	int		k;

	i = 0;
	k = 0;
	j = ft_size(s1) - 1;
	if (s1 == NULL)
		return (NULL);
	while (set && s1[i] && check_char(s1[i], set) == 1)
		i++;
	while (set && j >= i && check_char(s1[j], set) == 1)
		j--;
	if (!(str = (char*)malloc(sizeof(char) * (j - i) + 2)))
		return (NULL);
	while (i <= j)
	{
		str[k] = s1[i];
		k++;
		i++;
	}
	str[k] = '\0';
	return (str);
}
