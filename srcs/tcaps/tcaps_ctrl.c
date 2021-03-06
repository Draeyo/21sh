/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_ctrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:01:03 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 12:01:03 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ctrl_up_is_not_on_prompt(t_env *e)
{
	if (TCAPS.nb_line == 2 && TCAPS.nb_col < (int)ft_strlen(e->prompt))
		return (0);
	return (-1);
}

/*
**  INSTRUCTION FOR "Ctrl + ARROW ->" KEYS
*/

void		tcaps_ctrl_mov_right(t_env *e)
{
	int		i;

	i = NB_MOVE;
	while ((i > 0 && i != NB_READ && e->line[i - 1] == ' ')
			|| (!i && NB_READ))
	{
		move_right(e);
		++i;
	}
	while (i > 0 && i != NB_READ && e->line[i - 1] != ' ')
	{
		move_right(e);
		++i;
	}
	while (e->line[i] == '-' || e->line[i] == ' ')
	{
		move_right(e);
		++i;
	}
}

/*
**  INSTRUCTION FOR "Ctrl + ARROW <-" KEYS
*/

void		tcaps_ctrl_mov_left(t_env *e)
{
	int	i;

	i = NB_MOVE;
	while (i > 0 && (e->line[i - 1] == ' ' || e->line[i - 1] == '-'))
	{
		xputs(TGETSTR_LE);
		--NB_MOVE;
		--i;
	}
	while ((i && e->line[i - 1] != ' '))
	{
		xputs(TGETSTR_LE);
		--NB_MOVE;
		--i;
	}
	while (e->line[i] == '-')
	{
		move_right(e);
		++i;
	}
}

/*
**  INSTRUCTION FOR "Ctrl + ARROW UP/DOWN"
**	ARROW_UP	== 65
**	ARROW_DOWN	== 66
*/

static void	tcaps_ctrl_up_down(t_env *e, char buf[3])
{
	int		line;

	line = WIN_WIDTH;
	tcaps_recalc_pos(e);
	if (buf[2] == ARROW_UP && ctrl_up_is_not_on_prompt(e))
	{
		if (TCAPS.nb_line > 1)
		{
			while (line--)
			{
				xputs(TGETSTR_LE);
				--NB_MOVE;
			}
			tcaps_recalc_pos(e);
		}
	}
	else if (buf[2] == ARROW_DOWN)
	{
		while (line-- && NB_MOVE < NB_READ)
			move_right(e);
	}
}

/*
**  INSTRUCTION FOR "Ctrl + ARROW" KEYS
**
**	tcaps_check_key(buf, 59, 53, 68)): Ctrl + LEFT  arrow
**	NOT YET tcaps_check_key(buf, 59, 53, 67)): Ctrl + RIGHT arrow
*/

void		tcaps_ctrl_mov(t_env *e)
{
	char	buf[3];

	read(0, buf, 3);
	if (tcaps_check_key(buf, 59, 53, 67))
		tcaps_ctrl_mov_right(e);
	else if (tcaps_check_key(buf, 59, 53, 68))
		tcaps_ctrl_mov_left(e);
	else
		tcaps_ctrl_up_down(e, buf);
	tcaps_recalc_pos(e);
}
