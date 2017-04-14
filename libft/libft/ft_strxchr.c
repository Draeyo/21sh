/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:56:27 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:56:27 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description:
**		this function returns the address of the x-th char in a string
*/

char		*ft_strxchr(const char *s, char c, int x)
{
	if (s)
	{
		while (*s && x)
		{
			if (*s == (char)c)
				--x;
			if (!x)
				return ((char*)s);
			++s;
		}
		if (c == '\0')
			return ((char*)s);
		return (NULL);
	}
	return (NULL);
}
