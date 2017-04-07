/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:15:38 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/07 14:15:38 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	delete_char(t_env *e, int pos)
{
	int		i;
	int		j;
	char	*new;

	i = -1;
	j = -1;
	if (!(new = ft_strnew((int)ft_strlen(e->line) - 1)))
		return ;
	while (e->line[++i])
	{
		if (i == pos)
			++i;
		new[++j] = e->line[i];
	}
	new[++j] = '\0';
	strfree(&e->line);
	e->line = new;
}
