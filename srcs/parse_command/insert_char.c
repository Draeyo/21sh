/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 11:59:41 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 11:59:41 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	insert_char(t_env *e, char c, int pos)
{
	int		i;
	int		j;
	char	*new;

	i = -1;
	j = -1;
	if (!(new = ft_strnew((int)ft_strlen(e->line) + 1)))
		return ;
	while (e->line[++i])
	{
		if (++j == pos)
			new[j++] = c;
		new[j] = e->line[i];
	}
	new[++j] = '\0';
	strfree(&e->line);
	e->line = new;
}
