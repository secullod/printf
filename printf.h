/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secullod <secullod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:21:52 by secullod          #+#    #+#             */
/*   Updated: 2020/07/15 14:21:55 by secullod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct	s_flags{
	int		type;
	int		zero;
	int		left;
	int		precision;
	int		width;
	int		period;
	int		printed;
	int		neg;
	int		pzero;
	int		size;
	int		i;
}				t_flags;

void			print_arg(va_list args, t_flags *formatting);
int				find_type(char type);
int				fix_flags(t_flags *formatting);
int				set_flags(char *format, t_flags *formatting, va_list args);
int				ft_printf(char *format, ...);

void			print_s(va_list args, t_flags *formatting);
void			print_sp(char *s, t_flags *formatting);
void			print_c(va_list args, t_flags *formatting);
void			print_per(t_flags *formatting);
void			print_diu(va_list args, t_flags *formatting);

void			print_xx(va_list args, t_flags *formatting);
void			print_p(t_flags *formatting, va_list args);
void			print_p_help(t_flags *formatting);

void			ft_printchar(int c, t_flags *formatting);
void			ft_printwidth_c(t_flags *formatting);
void			ft_printstr(char *s, t_flags *formatting);
void			ft_printwidth_sp(char *s, t_flags *formatting);
void			ft_printper(t_flags *formatting);

void			ft_printwidth_per(t_flags *formatting);
void			ft_printxx(char *str, t_flags *formatting);
void			ft_printwidth_xx(char *str, t_flags *formatting);
long			ft_printnbr(long n, t_flags *formatting);
long			ft_printwidth_diu(long n, t_flags *formatting);

int				ft_strlen(const char *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			set_struct(t_flags *formatting);

int				ft_isdigit(int c);
char			*ft_capitalize(char *str);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_toupper(int c);
int				nb_size(long n);

void			ft_putnbr_fd(long n, int fd);
int				ft_atoi(const char *nptr, t_flags *formatting, char *format);
int				hexlen(long long num, int len);
char			*ft_itoa_hex_2(int sign, int len,
				long long num, unsigned long int n);
char			*ft_itoa_hex(unsigned long int n);

char			*ft_itoa_uhex_2(int sign, int len,
				long long num, unsigned int n);
char			*ft_itoa_uhex(unsigned int n);

#endif
