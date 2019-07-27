/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:09:13 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/20 16:34:39 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	int	i;
	int	j;

	i = -1;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[++i] && (size_t)i < size)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s1[i + j] == s2[j] && s1[i + j] &&
					((size_t)i + (size_t)j++) < size)
				if (s2[j] == '\0')
					return ((char *)&s1[i]);
		}
		if (((size_t)i + (size_t)j) >= size)
			return (NULL);
	}
	return (NULL);
}
