/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenali <bbenali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:54:43 by bbenali           #+#    #+#             */
/*   Updated: 2019/11/04 19:15:13 by bbenali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*d;

	d = *lst;
	while (d != NULL)
	{
		(*del)(d->content);
		d = d->next;
		free(*lst);
		*lst = d;
	}
	*lst = NULL;
}
