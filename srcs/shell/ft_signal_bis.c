/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:00:15 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/17 18:10:54 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	ft_sigint_reset(t_env *e)
{
	if (!e->child_running)
	{
		tcaps_ctrl_end(e);
		e->hdoc_nb = 0;
		strfree(&e->herestock);
		strfree(&e->line);
		strfree(&MULTI);
		HIST_MOVE = -1;
		ft_reset_heredocs(e);
		ft_putstr("\n\n");
		strfree(&e->prompt);
		e->prompt = ft_create_prompt(e, STD_PROMPT);
		ft_prompt(e->prompt);
	}
}

void		ft_sigint(t_env *e)
{
	e->check_ctrl_c = 1;
	if (e->c_match)
	{
		e->check_ctrl_c = 0;
		e->selected = -42;
		print_auto_completion(e, NULL, NULL, NULL);
		xputs(e->struct_tputs.cd);
		valid_selection(e);
	}
	ft_sigint_reset(e);
}
