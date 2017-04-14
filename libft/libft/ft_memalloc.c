/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:54:47 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:54:47 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION:
**     Allocates (with malloc(3)) and returns a “fresh” memory
**     area. The memory allocated is initialized to 0. If the allocation
**     fails, the function returns NULL.
*/

void	*ft_memalloc(size_t size)
{
	void	*space;

	space = NULL;
	if (size == 0 || (space = malloc(size)) == NULL)
		return (NULL);
	ft_memset(space, 0, size);
	return (space);
}
