/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_magic_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:00:27 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/17 17:14:32 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	manage_check_red(t_env *e, int i)
{
	if (e->magic[i + 1].type
		&& (is_input_redir(e, i) || is_output_redir(e, i) || is_heredoc(e, i))
		&& (is_input_redir(e, i + 1) || is_output_redir(e, i + 1) || \
			is_heredoc(e, i + 1)))
		return (token_error(e, i + 1));
	else if (!e->magic[i + 1].type && !is_aggregator(e, i))
		return (token_error(e, i));
	return (0);
}

static int	check_magic_content_bis(t_env *e, int i)
{
	if (is_redirection(e, i) && manage_check_red(e, i) == -1)
		return (-1);
	else if (e->magic[i + 1].cmd && !ft_strcmp(e->magic[i].cmd, ";")
			&& !ft_strstr(e->magic[i + 1].cmd, ";"))
		return (token_error(e, i + 1));
	else if (e->magic[i + 1].cmd
			&& ((is_operator(e, i) && is_operator(e, i + 1))
				|| (is_redir_pipe(e, i) && is_redir_pipe(e, i + 1))))
		return (token_error(e, i + 1));
	else if (!e->magic[i + 1].cmd && e->magic[i].cmd && is_redirection(e, i))
	{
		if ((ft_strstr(e->magic[i].cmd, ">&")
					&& e->magic[i].cmd[ft_strlen(e->magic[i].cmd) - 1] != '&'))
			return (0);
		return (ft_error("syntax error near unexpected token", \
					"'newline'", NULL));
	}
	return (0);
}

static int	is_device(t_env *e, int i)
{
	struct stat	stat;

	ft_bzero(&stat, sizeof(struct stat));
	lstat(e->magic[i].cmd, &stat);
	if (stat.st_rdev)
		return (1);
	return (0);
}

int			check_magic_content(t_env *e, int i)
{
	if (is_input_redir(e, i) && is_magic(e, i + 1) && is_device(e, i + 1))
	{
		return (ft_error(e->magic[i + 1].cmd,
					"device can't be used as stdin", NULL));
	}
	if (!e->magic[i + 1].cmd && is_redirection(e, i)
		&& !is_redir_pipe(e, i) && !is_aggregator(e, i + 1) && \
		!is_aggregator(e, i))
	{
		return (ft_error("syntax error near unexpected token", \
					"'newline'", NULL));
	}
	if (!i && is_operator(e, i))
		return (token_error(e, i));
	return (check_magic_content_bis(e, i));
}
