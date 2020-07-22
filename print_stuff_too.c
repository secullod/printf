/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff_too.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secullod <secullod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:25:18 by secullod          #+#    #+#             */
/*   Updated: 2020/07/20 21:44:20 by secullod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_xx(va_list args, t_flags *formatting)
{
	char	*s;

	s = ft_itoa_uhex(va_arg(args, unsigned int));
	if (formatting->type == 7)
		ft_capitalize(s);
	if (s[0] == '0' && formatting->pzero == 1)
	{
		formatting->width++;
		ft_printwidth_xx(s, formatting);
	}
	else if (formatting->left == 0)
	{
		ft_printwidth_xx(s, formatting);
		ft_printxx(s, formatting);
	}
	else
	{
		ft_printxx(s, formatting);
		ft_printwidth_xx(s, formatting);
	}
	free(s);
}

void	print_p_help(t_flags *formatting)
{
	formatting->precision = 2;
	formatting->left == 0 ? ft_printwidth_sp("0x", formatting)
	: ft_putstr_fd("0x", 1);
	if (formatting->left == 0)
		ft_putstr_fd("0x", 1);
	else
		ft_printwidth_sp("0x", formatting);
}

void	print_p(t_flags *formatting, va_list args)
{
	unsigned long int	uxx;
	char				*s;
	char				*x;

	uxx = va_arg(args, unsigned long int);
	if (uxx == 0 && formatting->precision == 0)
	{
		formatting->printed = 2;
		if (formatting->width == 0)
			ft_putstr_fd("0x", 1);
		else
			print_p_help(formatting);
	}
	else
	{
		formatting->precision = -1;
		x = ft_itoa_hex(uxx);
		s = ft_strjoin("0x", x);
		print_sp(s, formatting);
		free(s);
		free(x);
	}
}
