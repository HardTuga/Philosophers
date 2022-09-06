/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 11:21:23 by pcampos-          #+#    #+#             */
/*   Updated: 2022/04/29 10:01:56 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy(char *dst, const char *src, int n)
{
	if (dst && src)
	{
		while (n--)
			*dst++ = *src++;
	}
}

int	ft_putp(unsigned long n)
{
	int				i;
	unsigned long	c;
	char			hexa[16];

	ft_strcpy(hexa, "0123456789abcdef", 16);
	if (n >= 16)
		ft_putp(n / 16);
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
