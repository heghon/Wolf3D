/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:52:20 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/20 16:32:34 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	int		i;
	char	*string;

	string = (char *)str;
	i = -1;
	while ((size_t)++i != n)
		string[i] = c;
	return (string);
}
