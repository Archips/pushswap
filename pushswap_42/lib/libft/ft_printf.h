/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:22:58 by athirion          #+#    #+#             */
/*   Updated: 2021/12/03 10:28:58 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

void	ft_putnbrbase(long n, int baselen, char *base, int *len);
void	ft_putnbrbase_ptr(unsigned long n, int baselen, char *base, int *len);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);

int		ft_chr(va_list args);
int		ft_str(va_list args);
int		ft_ptr(va_list args);
int		ft_nbr(va_list args);

int		ft_uni(va_list args);
int		ft_hx1(va_list args);
int		ft_hx2(va_list args);
int		ft_pct(va_list args);

int		ft_fmt_index(char c);
void	ft_fmt(int (*fmt[8])(void *));
int		ft_parse_fmt(int (*fmt[8])(void *), const char *format, va_list args);
int		ft_printf(const char *format, ...);
#endif
