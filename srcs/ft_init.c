/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:22:14 by lfabbro           #+#    #+#             */
/*   Updated: 2017/02/10 15:36:15 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		ft_set_prompt(t_env *e)
{
	e->prompt = ft_strdup("$> ");
}

static int		ft_set_home(t_env *e)
{
	char		*tmp;

	e->home = NULL;
	tmp = NULL;
	if ((tmp = ft_getenv(e->env, "HOME")))
	{
		e->home = ft_strdup(tmp);
		free(tmp);
		return (1);
	}
	return (0);
}

static void		ft_set_shlvl(t_env *e)
{
	char	*lvl;
	int		tmp;

	if ((lvl = ft_getenv(e->env, "SHLVL")))
	{
		tmp = ft_atoi(lvl) + 1;
		free(lvl);
		lvl = ft_itoa(tmp);
		ft_setenv(&e->env, "SHLVL", lvl);
		free(lvl);
	}
	else
		ft_setenv(&e->env, "SHLVL", "1");
}

void			ft_init(t_env *e, int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	e->history = NULL;
	if (ft_read_history(e) < 0)
	{
		ft_free_tab(e->history);
		e->history = NULL;
	}
	ft_bzero(e->buf, 3);
	e->x = 1;
	e->exit = 0;
	e->line = NULL;
	e->env = ft_tabdup(env);
	e->cmd = NULL;
	e->cut = NULL;
	e->check_remove_tab = 0;
	e->cat = NULL;
	e->i_mag = 0;
	ft_set_prompt(e);
	ft_set_shlvl(e);
	TCAPS.nb_move = 0;
	TCAPS.nb_read = 0;
	TCAPS.check_move = 0;
	TCAPS.hist_move = -1;
	TCAPS.nb_line = 1;
	TCAPS.nb_col = 0;
	FD.stdin = dup(STDIN_FILENO);
	FD.stdout = dup(STDOUT_FILENO);
	FD.stderr = dup(STDERR_FILENO);
	FD.last_red = NULL;
	if (e->env == NULL || !ft_set_home(e))
		ft_error("minishell", "warning: no home set", NULL);
	if ((TCAPS.term_name = ft_getenv(e->env, "TERM")) == NULL)
		TCAPS.term_name = ft_strdup("xterm");
	if (tgetent(NULL, TCAPS.term_name) == ERR)
		ft_printf("GERRER L'ERROR");
	if (tcgetattr(0, &TCAPS.termos) == -1 || tcgetattr(0, &TCAPS.save) == -1)
		ft_printf("GERRER L'ERROR");
	TCAPS.termos.c_lflag &= ~(ICANON);
	TCAPS.termos.c_lflag &= ~(ECHO);
	TCAPS.termos.c_cc[VMIN] = 1;
	TCAPS.termos.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &TCAPS.termos) == -1)
		ft_printf("GERRER L'ERROR");
	xputs("am");
	xputs("bw");
}