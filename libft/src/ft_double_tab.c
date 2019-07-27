/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 11:17:38 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/22 11:57:08 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_double_tab(int width, int height)
{
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * (width + 1))))
		return (NULL);
	tab[width] = NULL;
	while (width--)
	{
		if (!(tab[width] = (char *)malloc(sizeof(char) * (height + 1))))
			return (NULL);
		tab[width][height] = '\0';
	}
	return (tab);
}
