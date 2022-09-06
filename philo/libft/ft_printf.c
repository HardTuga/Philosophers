/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 11:19:07 by pcampos-          #+#    #+#             */
/*   Updated: 2022/04/29 10:01:39 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	argtype(va_list ap, const char *str, int i)
{
	if (str[i + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (str[i + 1] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (str[i + 1] == 'p')
	{
		ft_putstr("0x");
		return (2 + ft_putp(va_arg(ap, unsigned long)));
	}
	else if (str[i + 1] == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (str[i + 1] == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	else if (str[i + 1] == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int)));
	else if (str[i + 1] == 'x')
		return (ft_putnbr_hexa(va_arg(ap, unsigned int), 1));
	else if (str[i + 1] == 'X')
		return (ft_putnbr_hexa(va_arg(ap, unsigned int), 0));
	else if (str[i + 1] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += (argtype(ap, str, i));
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
