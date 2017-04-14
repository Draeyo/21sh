/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:54:54 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:54:54 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*dst_ptr;
	char const		*src_ptr;

	dst_ptr = (char*)dst;
	src_ptr = (char const*)src;
	while (n-- && src_ptr && dst_ptr)
		*dst_ptr++ = *src_ptr++;
	return (dst);
}
