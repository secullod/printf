/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secullod <secullod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:21:19 by secullod          #+#    #+#             */
/*   Updated: 2020/07/15 20:18:20 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_arg(va_list args, t_flags *formatting)
{
	if (formatting->type == 0)
		print_c(args, formatting);
	if (formatting->type == 1)
		print_s(args, formatting);
	if (formatting->type == 2)
		print_p(formatting, args);
	if (formatting->type == 3 || formatting->type == 4 || formatting->type == 5)
		print_diu(args, formatting);
	if (formatting->type == 6 || formatting->type == 7)
		print_xx(args, formatting);
	if (formatting->type == 8)
		print_per(formatting);
}

int		find_type(char type)
{
	int		t_index;
	char	*types;

	t_index = -1;
	types = "cspdiuxX%";
	while (types[++t_index])
		if (types[t_index] == type)
			return (t_index);
	return (-1);
}

int		fix_flags(t_flags *formatting)
{
	if (formatting->precision < 0)
		formatting->precision = -1;
	if (formatting->zero == 1 && (formatting->precision != -1
		|| formatting->left == 1))
		formatting->zero = 0;
	if (formatting->precision == 0)
		formatting->pzero = 1;
	if (formatting->width < 0)
	{
		formatting->width *= -1;
		formatting->left = 1;
	}
	return (1);
}

int		set_flags(char *format, t_flags *formatting, va_list args)
{
	while (format[formatting->i++])
	{
		if (format[formatting->i] == '0')
			formatting->zero = 1;
		else if (format[formatting->i] == '-')
			formatting->left = 1;
		else if (format[formatting->i] == '*'
		&& format[formatting->i - 1] != '.')
			formatting->width = va_arg(args, int);
		else if (format[formatting->i] == '.')
			format[formatting->i + 1] == '*'
			? (formatting->precision = va_arg(args, int))
			: (formatting->precision =
			ft_atoi(&format[formatting->i + 1], formatting, format));
		else if (ft_isdigit(format[formatting->i]) &&
		format[formatting->i] != '0')
			formatting->period == 0
			? (formatting->width =
			ft_atoi(&format[formatting->i], formatting, format))
			: (formatting->precision =
			ft_atoi(&format[formatting->i], formatting, format));
		else if ((formatting->type = find_type(format[formatting->i])) != -1)
			return (fix_flags(formatting));
	}
	return (0);
}

int		ft_printf(char *format, ...)
{
	va_list	args;
	t_flags	formatting;

	va_start(args, format);
	formatting.printed = 0;
	formatting.i = 0;
	while (format[formatting.i])
	{
		set_struct(&formatting);
		if (format[formatting.i] != '%')
			ft_printchar(format[formatting.i], &formatting);
		else
		{
			if (!set_flags(format, &formatting, args))
				return (0);
			print_arg(args, &formatting);
		}
		formatting.i++;
	}
	return (formatting.printed);
}
