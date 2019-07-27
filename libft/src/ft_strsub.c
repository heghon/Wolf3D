/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:33:04 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/22 11:51:49 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;

	if (s)
	{
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		i = -1;
		while (len > 0 && ++i >= 0)
		{
			str[i] = s[i + start];
			len--;
		}
		str[i + 1] = '\0';
		return (str);
	}
	return (NULL);
}
