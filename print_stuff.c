/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secullod <secullod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:25:01 by secullod          #+#    #+#             */
/*   Updated: 2020/07/15 14:25:04 by secullod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_s(va_list args, t_flags *formatting)
{
	char	*s;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";
	if (formatting->left == 0)
		ft_printwidth_sp(s, formatting);
	else
		ft_printstr(s, formatting);
	if (formatting->left == 0)
		ft_printstr(s, formatting);
	else
		ft_printwidth_sp(s, formatting);
}

void	print_sp(char *s, t_flags *formatting)
{
	if (formatting->left == 0)
		ft_printwidth_sp(s, formatting);
	else
		ft_printstr(s, formatting);
	if (formatting->left == 0)
		ft_printstr(s, formatting);
	else
		ft_printwidth_sp(s, formatting);
}

void	print_c(va_list args, t_flags *formatting)
{
	char	c;

	c = va_arg(args, int);
	if (formatting->left == 0)
		ft_printwidth_c(formatting);
	else
		ft_printchar(c, formatting);
	if (formatting->left == 0)
		ft_printchar(c, formatting);
	else
		ft_printwidth_c(formatting);
}

void	print_per(t_flags *formatting)
{
	if (formatting->left == 0)
		ft_printwidth_per(formatting);
	else
		ft_printper(formatting);
	if (formatting->left == 0)
		ft_printper(formatting);
	else
		ft_printwidth_per(formatting);
}

void	print_diu(va_list args, t_flags *formatting)
{
	long	num;

	if (formatting->type == 5)
		num = (long)va_arg(args, unsigned int);
	else
		num = (long)va_arg(args, int);
	if (num == 0 && formatting->pzero == 1)
	{
		formatting->width++;
		ft_printwidth_diu(num, formatting);
	}
	else if (formatting->left == 0)
		ft_printnbr(ft_printwidth_diu(num, formatting), formatting);
	else
		ft_printwidth_diu(ft_printnbr(num, formatting), formatting);
}
