/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:55:59 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:55:59 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	size_t	i;
	size_t	slen;
	char	*dup;

	i = -1;
	slen = ft_strlen(src);
	if ((dup = ft_strnew(n)) == NULL)
		return (NULL);
	while (++i < n && i < slen)
		dup[i] = src[i];
	dup[i] = '\0';
	return (dup);
}
