/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_print_stuff_too.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secullod <secullod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:24:48 by secullod          #+#    #+#             */
/*   Updated: 2020/07/15 14:24:50 by secullod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printwidth_per(t_flags *formatting)
{
	while (formatting->width - (formatting->precision > 1
	? formatting->precision : 1) > 0)
	{
		if (formatting->zero == 1 && formatting->left != 1)
			ft_printchar('0', formatting);
		else
			ft_printchar(' ', formatting);
		formatting->width--;
	}
}

void	ft_printxx(char *str, t_flags *formatting)
{
	long	size;
	int		prec;

	size = ft_strlen(str);
	prec = formatting->precision;
	while (prec-- - size > 0)
		ft_printchar('0', formatting);
	ft_putstr_fd(str, 1);
	formatting->printed += size;
}

void	ft_printwidth_xx(char *str, t_flags *formatting)
{
	int		size;

	size = ft_strlen(str);
	while (formatting->width - (formatting->precision > size
	? formatting->precision : size) > 0)
	{
		if (formatting->zero == 1 && formatting->left != 1)
			ft_printchar('0', formatting);
		else
			ft_printchar(' ', formatting);
		formatting->width--;
	}
}

long	ft_printnbr(long n, t_flags *formatting)
{
	long	size;
	int		prec;

	size = nb_size(n);
	prec = formatting->precision;
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', 1);
		formatting->printed++;
		formatting->width++;
		formatting->neg = 1;
	}
	while (prec-- - size > 0)
		ft_printchar('0', formatting);
	ft_putnbr_fd(n, 1);
	formatting->printed += size;
	return (n);
}

long	ft_printwidth_diu(long n, t_flags *formatting)
{
	int		size;

	formatting->precision > nb_size(n)
	? (size = formatting->precision)
	: (size = nb_size(n));
	if (n < 0 && formatting->zero == 1)
	{
		n = -n;
		ft_putchar_fd('-', 1);
		formatting->printed++;
		size++;
	}
	else if (n < 0)
		size++;
	else if (formatting->neg == 1 && formatting->left == 1 && n > 0)
		size = size + 2;
	while (formatting->width - size > 0)
	{
		if (formatting->zero == 1 && formatting->left != 1)
			ft_printchar('0', formatting);
		else
			ft_printchar(' ', formatting);
		formatting->width--;
	}
	return (n);
}
