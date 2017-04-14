/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:56:24 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:56:24 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*trun;
	size_t	i;

	i = 0;
	if (s && len)
	{
		if ((trun = ft_strnew(len)) == NULL)
			return (NULL);
		while (i < len)
		{
			trun[i] = s[start + i];
			++i;
		}
		return (trun);
	}
	return (NULL);
}
