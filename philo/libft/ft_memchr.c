/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:31:39 by pcampos-          #+#    #+#             */
/*   Updated: 2021/10/28 14:56:45 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	char	*s;
	char	ch;

	i = 0;
	s = (char *)str;
	ch = (char)c;
	while (i < n)
	{
		if (s[i] == ch)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
