/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:55:45 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:55:45 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t a;
	size_t b;
	size_t c;

	a = ft_strlen(src);
	b = ft_strlen(dst);
	if (b < size)
	{
		c = size - b - 1;
		ft_strncat(dst, src, c);
		dst[b + c] = '\0';
		return (a + b);
	}
	return (size + a);
}
