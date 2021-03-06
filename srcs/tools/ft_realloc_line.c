/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:01:34 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 12:03:30 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_realloc_delete_char(t_env *e, int pos)
{
	char	*new;
	int		len;
	int		i;
	int		j;

	if (e->line)
		len = (int)ft_strlen(e->line);
	else
		return (NULL);
	if (!(new = ft_strnew(len)))
	{
		strfree(&e->line);
		return (NULL);
	}
	i = -1;
	j = -1;
	if (len >= 1)
		while (e->line[++i])
			if (i != pos)
				new[++j] = e->line[i];
	strfree(&e->line);
	return (new);
}

/*
**	Appends new character at the end of line
**	(realloc it)
*/

char	*ft_realloc_line(t_env *e, char c)
{
	char	*new;
	int		len;
	int		i;

	if (e->line)
		len = ft_strlen(e->line) + 1;
	else
		len = 1;
	if (!(new = ft_strnew(len)))
		return (NULL);
	i = 0;
	if (len > 1)
		while (e->line[i])
		{
			new[i] = e->line[i];
			++i;
		}
	new[i] = c;
	strfree(&e->line);
	return (new);
}

char	*ft_delete_char(char *str, int pos)
{
	char	*new;
	int		len;
	int		i;
	int		j;

	if (str)
		len = (int)ft_strlen(str) - 1;
	else
		return (NULL);
	if (!(new = ft_strnew(len)))
	{
		strfree(&str);
		return (NULL);
	}
	i = -1;
	j = -1;
	if (len >= 1)
		while (str[++i])
			if (i != pos)
				new[++j] = str[i];
	strfree(&str);
	return (new);
}
