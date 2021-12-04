/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahiabenali <bahiabenali@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:40:20 by bbenali           #+#    #+#             */
/*   Updated: 2021/12/04 22:10:40 by bahiabenali      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./includes/ft_printf.h"

void	putchar_count(char c, t_printf *g)
{
	write(1, &c, 1);
	g->put++;
}

void	put_string(char *str, t_printf *g, va_list ap)
{
	while (str && *str != '\0')
	{
		while (*str && *str != '%')
		{
			putchar_count(*str, g);
			str++;
		}
		if (*str && *str == '%')
		{
			str++;
			if (*str == '%')
			{
				putchar_count(*str, g);
				str++;
			}
			else if (str && *str != '%')
			{
				init(str, g, ap);
				str = g->save;
				ft_clean(g);
			}
		}
	}
}

int		ft_printf(const char *str, ...)
{
	t_printf	g;
	va_list		ap;
	char		*s;

	s = (char*)str;
	va_start(ap, str);
	ft_bzero(&g, sizeof(t_printf));
	put_string(s, &g, ap);
	printf("%i\n", g.put);
	va_end(ap);
	return (g.put);
}

int		main(void)
{
	char	*chaine;
	int		test_int;
	int		*g;
	int		c;
	int		res;

	g = &test_int;
	chaine = "chat";
	test_int = 106;
	c = 7;
	res = printf("vrai printf = %p\n", g);
	printf("res = %i\n", res);
	ft_printf("  my printf = %p\n", g);
	return (0);
}
