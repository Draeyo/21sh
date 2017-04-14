/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:56:44 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:56:44 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tabndup(char **tab, size_t b)
{
	char	**dup;
	size_t	len;
	size_t	i;

	if ((dup = ft_tabnew(b)) == NULL)
		return (NULL);
	i = 0;
	len = ft_tablen(tab);
	while (i < b && i < len)
	{
		dup[i] = ft_strdup(tab[i]);
		++i;
	}
	dup[i] = NULL;
	return (dup);
}
