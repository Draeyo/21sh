/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:55:15 by lfabbro           #+#    #+#             */
/*   Updated: 2017/02/10 16:47:29 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char		*ft_tilde(t_env *e, char *current)
{
	char	*ret;
	char	*home;

	if (!(home = ft_getenv(e->env, "HOME")))
		return (NULL);
	ret = ft_strjoin(home, &current[1]);
	free(home);
	return (ret);
}

static int		ft_subs_tilde(t_env *e)
{
	int		k;
	char	*tmp;

	k = -1;
	tmp = NULL;
	while (e->cmd[++k])
		if (e->cmd[k][0] == '~')
		{
			tmp = ft_tilde(e, e->cmd[k]);
			free(e->cmd[k]);
			e->cmd[k] = tmp;
		}
	return (0);
}

static char		**ft_trim_split_cmd(t_env *e)
{
	char	**cmds;
	char	*trline;

	trline = ft_strxtrim_quote(e->line, '\t');
	cmds = ft_strsplit(trline, ';');
	free(trline);
	return (cmds);
}

static int		ft_exec_builtin(t_env *e)
{
	char	ret;

	ret = 0;
	if (ft_strequ(e->cmd[0], "exit") && ++ret)
		ft_exit(e);
	else if (ft_strequ(e->cmd[0], "env") && ++ret)
		ft_env(e);
	else if (ft_strequ(e->cmd[0], "setenv") && ++ret)
		ft_setenv_blt(e);
	else if (ft_strequ(e->cmd[0], "unsetenv") && ++ret)
		ft_unsetenv_blt(e);
	else if (ft_strequ(e->cmd[0], "cd") && ++ret)
		ft_chdir(e);
	else if (ft_strequ(e->cmd[0], "echo") && ++ret)
		ft_echo(e);
	else if (ft_strequ(e->cmd[0], "where") && ++ret)
		ft_where(e);
	else if (ft_strequ(e->cmd[0], "history") && ++ret)
		ft_history(e);
	return (ret);
}

int				ft_exec_cmd(t_env *e, char **cmd)
{
	int		ret;

	ret = 0;
	e->cmd_len = ft_tablen(cmd);
	ft_subs_tilde(e);
	if (e->cmd_len)
	{
		if ((ret = ft_exec_builtin(e)))
			;
		else
			ret = ft_exec(cmd, e);
	}
	ft_check_history(e);
	e->cmd_len = 0;
	return (ret);
}

static void		struct_find_red(t_env *e)
{
	++(e->i_mag);
	while (e->magic[e->i_mag].cmd && ft_strcmp(e->magic[e->i_mag].type, "red"))
	{
		++(e->i_mag);
	}
	if (!(e->magic[e->i_mag].cmd))
		e->i_mag = 0;
	ft_printf("[%d]: %s\n", e->i_mag, e->magic[e->i_mag].cmd);
}

int				ft_iter_pipes(t_env *e, char *cmds_i)
{
	int		i;
	int		ret;

	i = -1;
	FD.in = STDIN_FILENO;
//	ft_printf("IN: %d\n", in);
	e->cmd = ft_strsplit_quote(cmds_i, ' ');
	e->magic = struct_strsplit_quote(cmds_i, ' ');
	e->cat = ft_cmds_split(e);
	magic_type(e);
/*    for (int a = 0; e->cat[a] ; a++)
		for (int b = 0 ; e->cat[a][b] ; b++)
			ft_printf("e->cat[%d][%d]: %s\n", a, b, e->cat[a][b]);
    for (int a = 0; e->magic[a].cmd ; a++)
		ft_printf("magic[%d]: %s - %s\n", a, e->magic[a].cmd, e->magic[a].type);
*/	while (e->cat[++i + 1])
	{
		struct_find_red(e);
		if (pipe(FD.fd) < 0)
			return (ft_error(SH_NAME, "Pipe failed.", NULL));
		if (e->magic[e->i_mag].cmd && !ft_strcmp(e->magic[e->i_mag].cmd, ">"))
		{
			if (!FD.last_red && (FD.fd[1] = open(e->magic[e->i_mag + 1].cmd, ONE_RED_FLAGS, OPENFLAGS)) == -1)
				ft_printf("MANAGE ERROR");
			dup2(FD.fd[1], STDOUT_FILENO);
			dup2(FD.in, STDIN_FILENO);
		}
//		ft_printf("fd[0]: %d	fd[1]: %d\n", fd[0], fd[1]);
		ret = ft_exec_cmd(e, e->cat[i]);
		FD.in = FD.fd[0];
//		printf("last_red: %s\n", FD.last_red ? FD.last_red : "rien");
	}
	if ((e->magic[e->i_mag].cmd && !ft_strcmp(e->magic[e->i_mag].cmd, "|")) ||
		!e->i_mag)
	{
		FD.fd[1] = STDOUT_FILENO;
		ret = ft_exec_cmd(e, e->cat[i]);
	}
	else
	{
		dup2(FD.stdin, STDIN_FILENO);
		dup2(FD.stdout, STDOUT_FILENO);
		dup2(FD.stderr, STDERR_FILENO);
	}
//	FD.in = 0;
	if (FD.last_red)
	{
		free(FD.last_red);
		FD.last_red = NULL;
	}
	ft_triple_free(e);
	magic_free(e);
	return (ret);
}

int				ft_parse_line(t_env *e)
{
	int		i;
	int		ret;
	char	**cmds;

	i = -1;
	ret = 0;
	if ((cmds = ft_trim_split_cmd(e)) != NULL)
	{
		while (cmds[++i])
		{
			if (ft_matchquotes(cmds[i]) == 0)
				ret = ft_iter_pipes(e, cmds[i]);
			else
				ft_error(NULL, "Unmatched quote", NULL);
			e->check_remove_tab = 0;
		}
	}
	ft_free_tab(cmds);
	return (ret);
}
