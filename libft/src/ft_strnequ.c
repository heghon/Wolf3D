/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:09:01 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/20 16:34:27 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	int	i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = ft_strncmp(s1, s2, n);
	return (i == 0 ? 1 : 0);
}
