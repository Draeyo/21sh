/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:55:04 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:55:04 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_pow(int nb, int pow)
{
	int		i;
	long	tot;

	i = 1;
	if (pow == 0)
		return (1);
	tot = nb;
	while (i < pow)
	{
		tot *= nb;
		++i;
	}
	return (tot);
}
