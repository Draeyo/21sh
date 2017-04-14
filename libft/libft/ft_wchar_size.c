/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:56:55 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:56:55 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_wchar_size(wchar_t wchar)
{
	int			len;

	len = 0;
	if (wchar <= 0xFF)
		len = 1;
	else if (wchar <= 0xFFF)
		len = 2;
	else if (wchar <= 0xFFFF)
		len = 3;
	else if (wchar <= 0x10FFFF)
		len = 4;
	return (len);
}
