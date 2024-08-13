/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassa <cassassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:25:35 by cassassa          #+#    #+#             */
/*   Updated: 2024/08/13 16:25:36 by cassassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_printf(int n, int fd)
{
	long int	nb;
	char		c;
	int			len;
	int			sign;

	len = 0;
	sign = 0;
	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
		sign = 1;
	}
	if (nb > 9)
		len += ft_putnbr_printf(nb / 10, fd);
	nb = nb % 10;
	c = nb + 48;
	len++;
	write(fd, &c, 1);
	return (len + sign);
}
