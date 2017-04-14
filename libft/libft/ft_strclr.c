/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:55:29 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:55:29 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION:
**     Sets every character of the string to the value ’\0’
*/

void	ft_strclr(char *s)
{
	if (s)
		while (*s)
		{
			*s = '\0';
			++s;
		}
}
