/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahiabenali <bahiabenali@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:55:38 by bbenali           #+#    #+#             */
/*   Updated: 2021/12/04 21:16:45 by bahiabenali      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <libc.h>
# include <stdio.h>
# include <stdarg.h>
# include "../srcs/libft/libft.h"

typedef struct	s_printf
{
	int		min;
	int		zero;
	int		champ;
	int		star_champ;
	int		point_prec;
	int		prec;
	int		star_prec;
	int		champ2;
	int		prec2;
	int		s_size;
	int		c;
	int		s;
	int		p;
	int		d;
	int		i;
	int		u;
	int		x;
	int		m_x;
	int		pourcent;
	char	*s2;
	char	*s1;
	char	*s3;
	char	*save;
	int		put;
	char	*res;
	int		t;
	int		i2;
	unsigned int	un_i;
	char	*ret;
	int		sign;
	long int	l_i;
	unsigned long un_l;
}				t_printf;

int		ft_printf(const char *s, ...);
void	putchar_count(char c, t_printf *g);
void	put_string(char *str, t_printf *g, va_list ap);
void	init(char *str, t_printf *g, va_list ap);
void	init_flag(char *str, t_printf *g, va_list ap);
void	init_width(char *str, t_printf *g, va_list ap);
void	init_prec(char *str, t_printf *g, va_list ap);
void	init_type_c_s(char *str, t_printf *g, va_list ap);
void	check_type(t_printf *g);
void	check_s_prec(t_printf *g);
void	s_only(t_printf *g);
void	prec_only(t_printf *g);
void	width_only(t_printf *g);
void	width_min(t_printf *g);
void	width_prec_min(t_printf *g);
void	width_prec(t_printf *g);
void	put_struct_s(t_printf *g);
void	width_zero(t_printf *g);
void	check_c(t_printf *g);
void	c_only(t_printf *g);
void	c_width_only(t_printf *g);
void	c_width_min(t_printf *g);
void	check_i_prec(t_printf *g);
void	check_i_champ(t_printf *g);
void	prec_i(t_printf *g);
void	width_prec_i(t_printf *g);
void	width_prec_min_i(t_printf *g);
char	*ft_strrev(char *str);
char	*ft_itoa_conv(char *str, char neg, unsigned int nu);
char	*itoa_long(long int n);
char	*itoa(int n);
size_t	digit_count(long nb, int base);
void	ft_bzero(void *s, size_t n);
void	ft_clean(t_printf *g);
char	*ft_itoa_base_ll(unsigned long n, int b);
char	*ft_itoa_conv_base_ll(char *str, char neg, long long nu, int base);
char	*ft_strrev(char *str);
char	*ft_itoa_base(int n, int b);
char	*ft_itoa_conv_base(char *str, char neg, int nu, int base);
char	*ft_itoa_base_long(unsigned n, int b, t_printf *g);
void	ft_add_min(t_printf *g);
void	ft_free(t_printf *g);
void	init_type_int(char *str, t_printf *g, va_list ap);
void	check_s_champ(t_printf *g);
void	prec_i_cp(t_printf *g);
char	*ft_capitalize(char *str, t_printf *g);
void	init_type_p(char *str, t_printf *g, va_list ap);
char		*ft_strjoin(char const *s1, char const *s2);
int		ft_size(const char *s);

#endif
