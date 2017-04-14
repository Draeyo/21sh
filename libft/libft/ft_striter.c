/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:55:40 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:55:40 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION:
**     Applies the function f to each character of the string passed
**     as argument. Each character is passed by address to f to be
**     modified if necessary.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
	{
		if (*s)
		{
			while (*s)
			{
				f(s);
				++s;
			}
		}
	}
}
