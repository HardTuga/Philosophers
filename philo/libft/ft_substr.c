/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:52:19 by pcampos-          #+#    #+#             */
/*   Updated: 2021/10/28 15:41:39 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	sl;
	size_t	i;

	if (s == NULL)
		return (NULL);
	sl = ft_strlen(s);
	if (start >= sl)
	{
		new = malloc(sizeof(char));
		if (new == NULL)
			return (NULL);
		*new = '\0';
		return (new);
	}
	if (sl < len)
		return (ft_strdup(s + start));
	new = malloc(len + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (start < sl && i < len)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
