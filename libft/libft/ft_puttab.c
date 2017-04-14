/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:06:54 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/25 17:48:38 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_puttab(char **tab)
{
	int		i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i] != NULL)
		{
			ft_putendl(tab[i]);
			++i;
		}
	}
}
