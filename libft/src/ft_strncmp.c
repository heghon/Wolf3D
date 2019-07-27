/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:59:13 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/20 16:34:16 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	int	i;

	if (size == 0)
		return (0);
	i = -1;
	while (((char)s1[++i] || (char)s2[i]) && (size_t)i < size)
		if ((char)s1[i] != (char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
