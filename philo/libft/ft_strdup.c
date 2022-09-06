/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:36:01 by pcampos-          #+#    #+#             */
/*   Updated: 2021/10/28 15:17:49 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*new;

	new = malloc(ft_strlen(str) + 1);
	if (new == NULL)
		return (NULL);
	ft_memmove(new, str, ft_strlen(str) + 1);
	return (new);
}
