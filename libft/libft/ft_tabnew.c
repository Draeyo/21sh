/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:56:46 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:56:46 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		**ft_tabnew(size_t size)
{
	char	**new;
	size_t	i;

	i = -1;
	if (size == 0 || (new = malloc(sizeof(new) * (size + 1))) == NULL)
		return (NULL);
	while (++i <= size)
		new[i] = NULL;
	return (new);
}
