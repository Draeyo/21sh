/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:00:08 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 12:00:08 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		exec_by_type(t_env *e, int i, int ret)
{
	if (!e->cat[i + 1] && redir_check_red(e, "|")
			&& !is_output_after(e, RED_INDEX + 1))
	{
		FD.fd[1] = STDOUT_FILENO;
		if (is_next_redir(e, RED_INDEX) == AGGREGATOR)
			struct_find_red(e);
		ret = ft_exec_cmd(e, e->cat[i]);
	}
	else
		ret = redir_exec_open(i, e);
	if (find_next_output(e, find_last_pipe(e)) && e->last_cmd_ret != 127)
		redir_fill_output(e);
	if (e->last_cmd_ret == 127)
		close(FD.fd[1]);
	dup2(FD.stdin, STDIN_FILENO);
	dup2(FD.stdout, STDOUT_FILENO);
	dup2(FD.stderr, STDERR_FILENO);
	return (ret);
}

static void		exec_end(t_env *e)
{
	e->is_valid_pipe = 1;
	ft_waitsons(e);
	ft_triple_free(e);
	if (e->hdoc_words)
		ft_free_tab(e->hdoc_words);
	e->hdoc_words = NULL;
	magic_free(e);
	RED_INDEX = 0;
	if (e->cmd)
		ft_tabfree(e->cmd);
	e->cmd = NULL;
	e->check_input = 0;
	e->hdoc_index = -1;
}

int				ft_iter_cmds(t_env *e, char *cmds_i)
{
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	FD.in = STDIN_FILENO;
	if (!(e->cmd = ft_strsplit_wo_quote_bs(cmds_i, ' ')) ||
		!(e->magic = struct_strsplit_quote_bs(cmds_i, ' ')))
		return (ft_error(NULL, "parsing error.", NULL));
	e->len_mag = struct_len(&e->magic);
	if (magic_type(e) == -1)
		return (-42);
	if ((e->cat = ft_cmds_split(e)) == NULL)
		return (-1);
	ft_create_file(e);
	while (++i < ft_catlen(e->cat) && e->cat[i])
	{
		ret = exec_by_type(e, i, ret);
		i += manage_operators(e, i, ret);
		e->is_out_close = 0;
		e->is_valid_pipe = is_last_cmd(e, RED_INDEX + 1) ? 0 : e->is_valid_pipe;
	}
	exec_end(e);
	return (ret);
}

int				ft_parse_line(t_env *e)
{
	int		i;
	int		ret;
	char	**cmds;

	i = -1;
	ret = 0;
	ft_store_history(e);
	if ((cmds = ft_trim_split_cmd(e)) != NULL)
	{
		while (cmds[++i])
		{
			if (substitution(e, &cmds[i]) == -1)
				ret = -42;
			else
				ret = ft_iter_cmds(e, cmds[i]);
			if (ret == -42)
				return (ret);
			tcaps_set(e);
		}
	}
	ft_free_tab(cmds);
	return (ret);
}
