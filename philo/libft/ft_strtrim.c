/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:41:16 by pcampos-          #+#    #+#             */
/*   Updated: 2021/10/28 15:38:26 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	a;
	size_t	b;
	char	*new;

	if (s1 == NULL)
		return (NULL);
	a = 0;
	b = ft_strlen(s1);
	while (ft_strchr(set, *(s1 + a)) != NULL)
		a++;
	while (ft_strrchr(set, *(s1 + b - 1)) != NULL)
		b--;
	new = ft_substr(s1, a, b - a);
	return (new);
}
