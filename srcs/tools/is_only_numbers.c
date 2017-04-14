/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_only_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:01:48 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 12:01:48 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_only_numbers(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!is_number(str[i]) && !(!i && str[i] == '-'))
			return (0);
	return (1);
}
