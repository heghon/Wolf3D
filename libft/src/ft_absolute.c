/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 09:20:15 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/20 16:29:59 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_absolute(int nbr)
{
	return (nbr < 0 ? -nbr : nbr);
}
