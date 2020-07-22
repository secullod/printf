/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_print_stuff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secullod <secullod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:24:40 by secullod          #+#    #+#             */
/*   Updated: 2020/07/15 14:24:42 by secullod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printchar(int c, t_flags *formatting)
{
	ft_putchar_fd(c, 1);
	formatting->printed++;
}

void	ft_printwidth_c(t_flags *formatting)
{
	while (formatting->width - 1 > 0)
	{
		ft_putchar_fd(' ', 1);
		formatting->width--;
		formatting->printed++;
	}
}

void	ft_printstr(char *s, t_flags *formatting)
{
	int		i;

	i = 0;
	if (formatting->precision == -1)
		ft_putstr_fd(s, 1);
	else
		while (i < formatting->precision && s[i])
			ft_putchar_fd(s[i++], 1);
	formatting->printed += (formatting->precision != -1 ? i : ft_strlen(s));
}

void	ft_printwidth_sp(char *s, t_flags *formatting)
{
	if (formatting->precision > ft_strlen(s))
		formatting->precision = ft_strlen(s);
	while (formatting->width - (formatting->precision >= 0
	? formatting->precision : ft_strlen(s)) > 0)
	{
		ft_putchar_fd(' ', 1);
		formatting->width--;
		formatting->printed++;
	}
}

void	ft_printper(t_flags *formatting)
{
	int		i;
	int		prec;

	i = 0;
	prec = formatting->precision;
	if (formatting->left == 1)
		ft_putchar_fd('%', 1);
	while (prec-- - 1 > 0 && i++ + 1 < formatting->width)
		ft_printchar(' ', formatting);
	if (formatting->left == 0)
		ft_putchar_fd('%', 1);
	formatting->printed++;
}
