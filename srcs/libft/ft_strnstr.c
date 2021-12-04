/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenali <bbenali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:51:53 by bbenali           #+#    #+#             */
/*   Updated: 2019/11/04 19:13:47 by bbenali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*find == '\0')
		return ((char*)str);
	if (*str == 0 || len == 0)
		return (NULL);
	while (str[i] && i + j < len)
	{
		j = 0;
		while (find[j] == str[i + j] && i + j < len)
		{
			if (find[j + 1] == '\0')
				return ((char*)&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
