/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_X.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:52:57 by tbaskhan          #+#    #+#             */
/*   Updated: 2022/01/19 16:11:54 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_upx_len(int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

void	ft_upx(int nb)
{
	if (nb >= 16)
	{
		ft_upx(nb / 16);
		ft_upx(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
			ft_putchar_fd((nb - 10 + 'A'), 1);
	}
}

int	ft_print_upx(int nb)
{
	if (nb == 0)
		write (1, "0", 1);
	else
		ft_upx(nb);
	return (ft_upx_len(nb));
}
