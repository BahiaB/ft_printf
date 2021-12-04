/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenali <bbenali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:50:03 by bbenali           #+#    #+#             */
/*   Updated: 2019/10/29 20:40:49 by bbenali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_sep(char s, char c)
{
	if (s == c)
		return (1);
	else
		return (0);
}

static char		**count_word(const char *s, char c, char **tab)
{
	int i;
	int cw;

	i = 0;
	cw = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], c) == 1)
			i++;
		if (s[i])
		{
			cw++;
			while (s[i] && is_sep(s[i], c) == 0)
				i++;
		}
	}
	if (!(tab = (char**)malloc(sizeof(char *) * (cw + 1))))
		return (NULL);
	tab[cw] = NULL;
	return (tab);
}

static char		**count_char(const char *s, char c, char **tab)
{
	int i;
	int cc;
	int l;

	i = 0;
	l = 0;
	while (s[i])
	{
		cc = 0;
		while (s[i] && is_sep(s[i], c) == 1)
			i++;
		if (s[i])
		{
			while (s[i] && is_sep(s[i], c) == 0)
			{
				i++;
				cc++;
			}
			if (!(tab[l] = (char*)malloc(sizeof(char) * (cc + 1))))
				return (NULL);
			l++;
		}
	}
	return (tab);
}

static char		**fill_tab(const char *s, char c, char **tab)
{
	int i;
	int l;
	int col;

	i = 0;
	l = 0;
	col = 0;
	while (s[i])
	{
		if (s[i] && is_sep(s[i], c) == 1)
			i++;
		if (s[i] && is_sep(s[i], c) == 0)
		{
			while (s[i] && is_sep(s[i], c) == 0)
			{
				tab[l][col] = s[i];
				col++;
				i++;
			}
			tab[l][col] = 0;
			l++;
			col = 0;
		}
	}
	return (tab);
}

char			**ft_split(const char *s, char c)
{
	char **tab;

	tab = NULL;
	tab = count_word(s, c, tab);
	if (tab == NULL)
		return (NULL);
	tab = count_char(s, c, tab);
	if (tab == NULL)
		return (NULL);
	tab = fill_tab(s, c, tab);
	return (tab);
}
