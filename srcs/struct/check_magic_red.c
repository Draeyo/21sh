/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_magic_red.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:00:28 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 12:00:28 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			token_error(t_env *e, int id)
{
	char	*ret;

	ret = NULL;
	if (!e->magic[RED_INDEX].cmd)
	{
		return (ft_error("syntax error near unexpected token",\
					"'newline'", NULL));
	}
	if ((int)ft_strlen(e->magic[id].cmd) > 2)
	{
		ret = ft_strnew(2);
		ret = ft_strncpy(ret, e->magic[id].cmd, 2);
	}
	else
		ret = ft_strdup(e->magic[id].cmd);
	ft_printfd(2, "%s: syntax error near unexpected token: \"%s\"\n",\
			SH_NAME, ret);
	strfree(&ret);
	return (-1);
}

static int	is_bad_first_arg(t_env *e)
{
	int		x;
	int		bs;
	char	quote;

	x = 0;
	bs = 0;
	quote = '\0';
	if (is_magic(e, 0) && (is_redirection(e, 0)))
	{
		while (e->magic[0].cmd[x])
		{
			if (!bs && e->magic[0].cmd[x] == '\\' && !quote)
				bs = 1;
			else
			{
				quote = ft_check_quote_bs(e->magic[0].cmd[x], quote, bs);
				if (!quote && !bs && (e->magic[0].cmd[x] == ';'
					|| e->magic[0].cmd[x] == '|' || e->magic[0].cmd[x] == '>'
					|| e->magic[0].cmd[x] == '&' || e->magic[0].cmd[x] == '<'))
					return (token_error(e, 0));
				bs = 0;
			}
		}
	}
	return (0);
}

int			check_magic_red(t_env *e)
{
	int	i;

	i = -1;
	if (is_bad_first_arg(e))
		return (-1);
	while (e->magic[++i].cmd)
		if (check_magic_content(e, i) == -1)
			return (-1);
	return (0);
}
