/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:22:34 by athirion          #+#    #+#             */
/*   Updated: 2021/12/03 10:29:21 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fmt_index(char c)
{
	int	index;

	index = 0 * (c == 'c')
		+ 1 * (c == 's')
		+ 2 * (c == 'p')
		+ 3 * (c == 'i' || c == 'd')
		+ 4 * (c == 'u')
		+ 5 * (c == 'x')
		+ 6 * (c == 'X')
		+ 7 * (c == '%');
	return (index);
}

void	ft_fmt(int (*fmt[8])(void *))
{
	fmt[0] = (void *)ft_chr;
	fmt[1] = (void *)ft_str;
	fmt[2] = (void *)ft_ptr;
	fmt[3] = (void *)ft_nbr;
	fmt[4] = (void *)ft_uni;
	fmt[5] = (void *)ft_hx1;
	fmt[6] = (void *)ft_hx2;
	fmt[7] = (void *)ft_pct;
}

int	ft_parse_fmt(int (*fmt[8])(void *), const char *format, va_list args)
{
	int	ret;

	ret = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			ret ++;
			format ++;
			continue ;
		}
		format ++;
		ret += ((*fmt[ft_fmt_index(*format ++)])(args));
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		(*fmt[8])(void *);
	va_list	args;
	int		ret;

	ret = 0;
	ft_fmt(fmt);
	va_start(args, format);
	ret = ft_parse_fmt(fmt, format, args);
	va_end(args);
	return (ret);
}
