/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_too_too.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secullod <secullod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:22:51 by secullod          #+#    #+#             */
/*   Updated: 2020/07/15 14:22:56 by secullod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_fd(long n, int fd)
{
	char	num;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -1 * n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	num = n % 10 + 48;
	ft_putchar_fd(num, fd);
}

int		ft_atoi(const char *nptr, t_flags *formatting, char *format)
{
	int	i;
	int	num;
	int	sign;

	num = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\r' || nptr[i] == '\f' ||
	nptr[i] == '\f' || nptr[i] == '\v' || nptr[i] == '\n' || nptr[i] == '\t')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		sign = nptr[i++] == '-' ? -1 : 1;
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		num = nptr[i + 1] >= '0' && nptr[i + 1] <= '9'
		? (num + nptr[i++] - '0') * 10
		: (num + nptr[i++] - '0');
	while (ft_isdigit(format[formatting->i + 1]))
		formatting->i++;
	return (sign * num);
}

int		hexlen(long long num, int len)
{
	while ((num /= 16) > 0)
		len++;
	return (len);
}

char	*ft_itoa_hex_2(int sign, int len, long long num, unsigned long int n)
{
	char		*str;

	sign = num < 0 ? 1 : 0;
	len = sign == 1 ? 2 : 1;
	num = num < 0 ? -num : num;
	len = hexlen(num, len);
	num = n;
	num = num < 0 ? -num : num;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	if (num == 0)
		str[len] = '0';
	while (num > 0)
	{
		if (num % 16 <= 9)
			str[len] = num % 16 + '0';
		else
			str[len] = num % 16 - 10 + 'a';
		num = num / 16;
		len--;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa_hex(unsigned long int n)
{
	int			sign;
	int			len;
	char		*str;
	long long	num;

	sign = 0;
	len = 0;
	num = n;
	str = ft_itoa_hex_2(sign, len, num, n);
	return (str);
}
