/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:01:36 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/17 18:06:20 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	free_hdoc_list(t_env *e)
{
	t_list	*tmp;

	e->hdoc = e->b_hdoc;
	while (e->hdoc)
	{
		tmp = e->hdoc->next;
		ft_free_tab(e->hdoc->content);
		e->hdoc->content = NULL;
		free(e->hdoc);
		e->hdoc = NULL;
		e->hdoc = tmp;
	}
	e->b_hdoc = NULL;
}

int			ft_reset_heredocs(t_env *e)
{
	e->same_node = -1;
	e->hdoc_index = -1;
	if (e->hdoc_words)
		ft_free_tab(e->hdoc_words);
	e->hdoc_words = NULL;
	free_hdoc_list(e);
	return (1);
}

int			ft_reset_line(t_env *e)
{
	if (e->raw)
		e->raw -= 1;
	strfree(&e->line);
	strfree(&e->line_bkp);
	strfree(&MULTI);
	ft_reset_heredocs(e);
	NB_MOVE = 0;
	NB_READ = 0;
	HIST_MOVE = -1;
	e->check_ctrl_c = 0;
	e->hdoc_nb = 0;
	e->quote = '\0';
	e->multi_quote = '\0';
	e->env_exec = 0;
	NB_COL = 0;
	NB_LINE = 0;
	return (0);
}
