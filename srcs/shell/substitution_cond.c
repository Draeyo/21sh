/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution_cond.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:19:35 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/07 14:19:37 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	substitution_cond(char **str, int *i, char *tmp)
{
	tmp = ft_strdup((*str));
	do_substitution(str, i, USERS_DIR, 0);
	if (access(&(*str)[*i], F_OK) == -1)
	{
		ft_strdel(str);
		*str = tmp;
	}
}
