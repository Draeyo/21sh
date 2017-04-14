/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:55:15 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:55:15 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION:
**      Outputs the integer n to the file descriptor fd
*/

int		ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	int				len;

	nb = n;
	len = 0;
	if (n < 0)
	{
		len += ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
		len += ft_putchar_fd(nb + '0', fd);
	return (len);
}
