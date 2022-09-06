/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:46:22 by pcampos-          #+#    #+#             */
/*   Updated: 2021/10/28 14:22:20 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checklen(int n)
{
	int	l;

	l = 0;
	if (n < 0)
		n *= -1;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	char	*new;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = checklen(n);
	if (n < 0)
		i++;
	new = (char *)malloc(sizeof(char) * (i + 1));
	if (new == NULL)
		return (NULL);
	new[i--] = '\0';
	if (n < 0)
	{
		new[0] = '-';
		n *= -1;
	}
	if (n == 0)
		new[0] = '0';
	while (n > 0)
	{
		new[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (new);
}
