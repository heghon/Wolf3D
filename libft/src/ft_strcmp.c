/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:42:50 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/20 16:13:34 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = -1;
	while ((char)s1[++i] || (char)s2[i])
		if ((char)s1[i] != (char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
