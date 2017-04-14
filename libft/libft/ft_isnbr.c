/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:54:26 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:54:26 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isnbr(char *str)
{
	int	is_nbr;

	is_nbr = 0;
	if (str)
	{
		while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
					*str == '\r' || *str == '\f' || *str == '\v'))
			++str;
		if (*str && (*str == '+' || *str == '-'))
			++str;
		if (*str >= '0' && *str <= '9')
			is_nbr = 1;
	}
	return (is_nbr);
}
