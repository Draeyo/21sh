/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:56:38 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:56:38 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tabcpy(char **dst, char **src)
{
	int		i;

	i = -1;
	if (src && dst)
	{
		while (src[++i])
		{
			dst[i] = ft_strdup(src[i]);
		}
		dst[i] = NULL;
	}
	return (dst);
}
