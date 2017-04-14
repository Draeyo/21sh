/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:54:59 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:54:59 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*sd;
	unsigned char	*ss;

	if (dst && src)
	{
		sd = (unsigned char *)dst;
		ss = (unsigned char *)src;
		if (dst > src)
		{
			sd += len;
			ss += len;
			while (len--)
				*--sd = *--ss;
		}
		else
			ft_memcpy(dst, src, len);
	}
	return (dst);
}
