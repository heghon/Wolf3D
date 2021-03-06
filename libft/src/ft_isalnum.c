/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:27:49 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/20 16:30:35 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	return (((c > 47 && c < 58) || (c > 64 && c < 91)
				|| (c > 96 && c < 123)) ? 1 : 0);
}
