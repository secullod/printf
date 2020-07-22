/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_too_too_too.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secullod <secullod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:24:25 by secullod          #+#    #+#             */
/*   Updated: 2020/07/15 14:24:27 by secullod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_itoa_uhex_2(int sign, int len, long long num, unsigned int n)
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

char	*ft_itoa_uhex(unsigned int n)
{
	int			sign;
	int			len;
	char		*str;
	long long	num;

	sign = 0;
	len = 0;
	num = n;
	str = ft_itoa_uhex_2(sign, len, num, n);
	return (str);
}
