/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:00:18 by pcampos-          #+#    #+#             */
/*   Updated: 2021/10/28 15:34:20 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && n > 0)
	{
		if (str1[i] != str2[i])
			break ;
		i++;
		n--;
	}
	if (str1[i] > str2[i] && n > 0)
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	else if (str1[i] < str2[i] && n > 0)
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	else
		return (0);
}
