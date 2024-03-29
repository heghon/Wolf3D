/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:52:05 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/20 16:12:00 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr(int n)
{
	unsigned int	i;

	i = (n < 0 ? -n : n);
	if (n < 0)
		ft_putchar('-');
	if (i < 10)
		ft_putchar(i + '0');
	else
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
}
