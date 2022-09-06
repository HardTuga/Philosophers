/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 11:20:35 by pcampos-          #+#    #+#             */
/*   Updated: 2022/04/29 10:01:50 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;
	int	c;

	i = 1;
	c = 1;
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_putstr("-2147483648"));
		i += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
	if (n >= 10)
	{
		while (n / c > 9)
		{
			c *= 10;
			i++;
		}
	}
	return (i);
}

int	ft_putunbr(unsigned int n)
{
	unsigned int	i;
	unsigned int	c;

	i = 1;
	c = 1;
	if (n >= 10)
		ft_putunbr(n / 10);
	ft_putchar((n % 10) + '0');
	if (n >= 10)
	{
		while (n / c > 9)
		{
			c *= 10;
			i++;
		}
	}
	return (i);
}

int	ft_putnbr_hexa(unsigned int n, int a)
{
	int		i;
	int		c;
	char	hexa[16];

	if (a == 1)
		ft_strcpy(hexa, "0123456789abcdef", 16);
	else
		ft_strcpy(hexa, "0123456789ABCDEF", 16);
	if (n >= 16)
		ft_putnbr_hexa(n / 16, a);
	ft_putchar(hexa[n % 16]);
	i = 1;
	c = 1;
	if (n >= 16)
	{
		while (n / c > 15)
		{
			c *= 16;
			i++;
		}
	}
	return (i);
}
