/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:54:40 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:54:40 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**     Takes as a parameter a link’s pointer address and frees the
**     memory of the link’s content using the function del given as
**     a parameter, then frees the link’s memory using free(3). The
**     memory of next musnt not be freed under any circumstance.
**     Finally, the pointer to the link that was just freed must be
**     set to NULL (quite similar to the function ft_memdel in the
**     mandatory part).
*/

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if ((*alst)->content)
	{
		del((*alst)->content, (*alst)->content_size);
		free((*alst)->content);
	}
	if ((void *)*alst)
		free((void *)*alst);
	*alst = NULL;
}
