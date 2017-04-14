/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:56:40 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:56:40 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tabdup(char **tab)
{
	char	**dup;
	int		i;

	i = 0;
	if ((dup = ft_tabnew(ft_tablen(tab))) == NULL)
		return (NULL);
	while (tab[i])
	{
		dup[i] = ft_strdup(tab[i]);
		++i;
	}
	dup[i] = NULL;
	return (dup);
}
