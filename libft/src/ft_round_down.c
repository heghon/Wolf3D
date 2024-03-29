/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:53:37 by bmenant           #+#    #+#             */
/*   Updated: 2019/07/02 10:43:48 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_round_down(int a, int b)
{
	return (a % b > 4 && a / b != 0 ? (a / b) - 1 : a / b);
}
