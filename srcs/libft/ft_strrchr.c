/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenali <bbenali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:52:12 by bbenali           #+#    #+#             */
/*   Updated: 2019/10/29 18:34:42 by bbenali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	int		i;

	a = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == a)
			return ((char*)&s[i]);
		i--;
	}
	return (NULL);
}
