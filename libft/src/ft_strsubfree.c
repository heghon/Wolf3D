/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:54:20 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/20 16:35:07 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strsubfree(char *s1, unsigned int start, size_t len)
{
	char	*str;

	str = ft_strsub(s1, start, len);
	free(s1);
	return (str);
}
