/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:01:31 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 12:01:31 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_job		*ft_new_job(t_job *next, int pid)
{
	t_job	*new;

	if ((new = malloc(sizeof(*new))) == NULL)
		return (NULL);
	new->next = next;
	new->pid = pid;
	return (new);
}
