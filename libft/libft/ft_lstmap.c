/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:54:43 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:54:43 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION:
**     Iterates a list lst and applies the function f to each link to
**     create a “fresh” list (using malloc(3)) resulting from the successive
**     applications of f. If the allocation fails, the function
**     returns NULL
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*new_list;
	t_list	*tmp;

	new_list = NULL;
	while (lst)
	{
		tmp = f(lst);
		if (!new_list)
		{
			new_list = tmp;
			ret = new_list;
			new_list->next = NULL;
		}
		else
		{
			new_list->next = tmp;
			new_list = new_list->next;
			tmp->next = NULL;
		}
		lst = lst->next;
	}
	return (ret);
}
