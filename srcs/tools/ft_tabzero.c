/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:01:41 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 12:01:41 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_tabzero(char **dbl_tab, int len_tab)
{
	int	i;

	i = -1;
	while (++i <= len_tab)
		dbl_tab[i] = NULL;
}
