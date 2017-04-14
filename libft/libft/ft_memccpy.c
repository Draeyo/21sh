/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:54:49 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:54:49 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	i = 0;
	dst_ptr = (unsigned char*)dst;
	src_ptr = (unsigned char*)src;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		if (dst_ptr[i] == (unsigned char)c)
			return (&dst_ptr[i + 1]);
		i++;
	}
	return (NULL);
}
