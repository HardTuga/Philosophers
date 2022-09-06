/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:07:13 by pcampos-          #+#    #+#             */
/*   Updated: 2021/10/28 15:14:46 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nsplit(char const *s, char c)
{
	int	i;
	int	ns;

	i = 0;
	ns = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			ns++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (ns);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	char	*str;
	size_t	ns;

	if (s == NULL)
		return (NULL);
	ns = nsplit(s, c);
	new = (char **)malloc(sizeof(char *) * (ns + 1));
	if (new == NULL)
		return (NULL);
	str = (char *)s;
	while (*s)
	{
		if (*s == c)
		{
			if (str != s)
				*(new ++) = ft_substr(str, 0, s - str);
			str = (char *)s + 1;
		}
		s++;
	}
	if (str != s)
		*(new ++) = ft_substr(str, 0, s - str);
	*new = 0;
	return (new - ns);
}
