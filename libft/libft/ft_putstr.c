/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:55:17 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:55:17 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION:
**     Outputs the string s to the standard output.
**     Returns the number or printed chars.
*/

int			ft_putstr(char const *s)
{
	if (s)
		return (write(1, s, (int)ft_strlen(s)));
	return (0);
}
