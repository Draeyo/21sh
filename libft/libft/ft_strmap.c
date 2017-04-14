/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:55:49 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:55:49 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION:
**     Applies the function f to each character of the string given
**     as argument to create a “fresh” new string (with malloc(3))
**     resulting from the successive applications of f.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	int		i;
	char	*new_str;

	i = 0;
	if (s && f)
	{
		len = ft_strlen(s);
		if ((new_str = malloc(sizeof(*s) * len)) == NULL)
			return (NULL);
		while (i < len)
		{
			new_str[i] = f(s[i]);
			++i;
		}
		new_str[i] = '\0';
		return (new_str);
	}
	return (NULL);
}
