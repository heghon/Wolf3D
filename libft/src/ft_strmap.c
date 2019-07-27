/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:16:35 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/20 16:34:04 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	unsigned int	i;
	char			*str;

	if (!(s == NULL || f == NULL))
	{
		if (!(str = (char*)malloc(sizeof(char) * (ft_strlen((char *)s) + 1))))
			return (NULL);
		i = -1;
		while (s[++i] != '\0')
			str[i] = f(s[i]);
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
