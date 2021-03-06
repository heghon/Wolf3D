/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:00:54 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/20 16:13:44 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, const char *src)
{
	int		i;

	i = -1;
	while (src[++i] != '\0')
		dest[i] = src[i];
	dest[i] = src[i];
	return (dest);
}
