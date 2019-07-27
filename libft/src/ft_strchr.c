/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:49:17 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/20 16:33:09 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == (char)c)
			return ((char *)&str[i]);
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
