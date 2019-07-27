/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:10:26 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/20 16:30:49 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_itoa(int n)
{
	unsigned int	i;
	int				neg;
	int				size;
	char			*s;

	neg = 0;
	size = 1;
	i = (n < 0 && ++neg ? -n : n);
	while (n /= 10)
		size++;
	if (!(s = (char *)malloc(sizeof(char) * (size + 1 + neg))))
		return (NULL);
	s[size + neg] = '\0';
	s[--size + neg] = (i % 10) + 48;
	while (i /= 10)
		s[--size + neg] = (i % 10) + 48;
	if (neg == 1)
		s[0] = '-';
	return (s);
}
