/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arc_to_rad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:33:36 by bmenant           #+#    #+#             */
/*   Updated: 2019/07/25 14:30:12 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

float	ft_arc_to_rad(float angle)
{
	return ((float)(angle * 0.017453292519943));
}