/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:23:39 by athirion          #+#    #+#             */
/*   Updated: 2022/04/13 16:01:49 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrbase(long n, int baselen, char *base, int *len)
{
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
		*len += 1;
	}
	if (n >= baselen)
		ft_putnbrbase((long)(n / baselen), baselen, base, len);
	*len += 1;
	write(1, &base[n % baselen], 1);
}

void	ft_putnbrbase_ptr(unsigned long n, int baselen, char *base, int *len)
{
	if ((int)n < 0)
	{
		n = -n;
		ft_putchar('-');
		*len += 1;
	}
	if (n >= (unsigned int)baselen)
		ft_putnbrbase_ptr(n / (unsigned long)(baselen), baselen, base, len);
	*len += 1;
	write(1, &base[n % (unsigned long)baselen], 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{	
		while (s[i])
		{
			ft_putchar(s[i]);
			i ++;
		}
	}
}

void	ft_putnbr(int n)
{
	long	ln;

	ln = n;
	if (ln < 0)
	{
		ln *= -1;
		ft_putchar('-');
	}
	if (ln > 9)
		ft_putnbr((int)(ln / 10));
	write(1, &"0123456789"[ln % 10], 1);
}
