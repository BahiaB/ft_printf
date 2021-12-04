/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenali <bbenali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:48:23 by bbenali           #+#    #+#             */
/*   Updated: 2019/11/04 16:15:30 by bbenali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	if (s == NULL && d == NULL)
		return (NULL);
	if (d < s)
	{
		return (ft_memcpy(d, s, len));
	}
	else if (d > s)
	{
		len++;
		while (--len > 0)
			d[len - 1] = s[len - 1];
	}
	return (dest);
}
