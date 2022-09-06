/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:20:34 by pcampos-          #+#    #+#             */
/*   Updated: 2021/10/28 15:27:02 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dl;
	size_t	sl;
	size_t	odl;

	odl = ft_strlen(dest);
	dl = ft_strlen(dest);
	sl = 0;
	if (dl > size)
		return (ft_strlen(src) + size);
	while (src[sl] != '\0' && dl < size)
	{
		dest[dl] = src[sl];
		sl++;
		dl++;
	}
	if (dl == size && sl != 0)
		dest[dl - 1] = '\0';
	else
		dest[dl] = '\0';
	return (ft_strlen(src) + odl);
}
