/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:48:34 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/20 16:32:15 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*src;

	dest = (char *)str1;
	src = (char *)str2;
	i = -1;
	while (++i < n)
		dest[i] = src[i];
	return ((void *)dest);
}
