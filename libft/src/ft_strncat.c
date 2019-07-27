/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:12:31 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/20 16:34:11 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] && (j < n))
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
