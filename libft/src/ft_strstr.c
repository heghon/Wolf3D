/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:27:29 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/20 16:34:57 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strstr(const char *meule_de_foin, const char *aiguille)
{
	int	i;
	int	j;

	i = -1;
	if (aiguille[i] == '\0')
		return ((char *)meule_de_foin);
	while (meule_de_foin[++i])
	{
		j = 0;
		if (meule_de_foin[i] == aiguille[j])
			while (meule_de_foin[i + j] == aiguille[j] && meule_de_foin[i + j])
				if (aiguille[++j] == '\0')
					return ((char *)&meule_de_foin[i]);
	}
	return (NULL);
}
