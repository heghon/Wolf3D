/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_tab_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 11:56:40 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/22 11:58:14 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		**ft_double_tab_int(int width, int height)
{
	int	**tab;

	if (!(tab = (int **)malloc(sizeof(int *) * (width + 1))))
		return (NULL);
	tab[width] = NULL;
	while (width--)
	{
		if (!(tab[width] = (int *)malloc(sizeof(int) * (height + 1))))
			return (NULL);
		tab[width][height] = '\0';
	}
	return (tab);
}
