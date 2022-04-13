/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fmt2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:23:28 by athirion          #+#    #+#             */
/*   Updated: 2021/12/03 10:12:51 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_chr(va_list args)
{
	char	c;

	c = (char) va_arg(args, int);
	ft_putchar(c);
	return (1);
}

int	ft_str(va_list args)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(args, char *);
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(str);
	while (str[i])
		i ++;
	return (i);
}

int	ft_ptr(va_list args)
{
	unsigned long	nb;
	int				*len;
	int				l;

	l = 0;
	len = &l;
	nb = va_arg(args, unsigned long);
	ft_putstr("0x");
	ft_putnbrbase_ptr(nb, 16, "0123456789abcdef", len);
	return (*len + 2);
}

int	ft_nbr(va_list args)
{
	long	nb;
	int		*len;
	int		l;

	l = 0;
	len = &l;
	nb = (long)va_arg(args, int);
	ft_putnbrbase(nb, 10, "0123456789", len);
	return (*len);
}
