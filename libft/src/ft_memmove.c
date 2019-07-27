/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:46:21 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/20 16:32:26 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	int				i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = -1;
	if (d > s)
		while ((size_t)i < n--)
			d[n] = s[n];
	else
		while ((size_t)++i < n)
			d[i] = s[i];
	return (dest);
}
