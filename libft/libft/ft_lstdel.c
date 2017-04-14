/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:54:38 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:54:38 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION:
**     Takes as a parameter the adress of a pointer to a link and
**     frees the memory of this link and every successors of that link
**     using the functions del and free(3). Finally the pointer to
**     the link that was just freed must be set to NULL (quite similar
**     to the function ft_memdel from the mandatory part).
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*ret;

	ret = NULL;
	ret = *alst;
	while (ret)
	{
		tmp = ret;
		ret = ret->next;
		if (tmp)
			ft_lstdelone(&tmp, del);
	}
	*alst = NULL;
}
