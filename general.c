/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secullod <secullod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:22:16 by secullod          #+#    #+#             */
/*   Updated: 2020/07/15 14:22:20 by secullod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	set_struct(t_flags *formatting)
{
	formatting->type = 0;
	formatting->zero = 0;
	formatting->precision = -1;
	formatting->left = 0;
	formatting->width = 0;
	formatting->period = 0;
	formatting->neg = 0;
	formatting->pzero = 0;
	formatting->size = 0;
}
