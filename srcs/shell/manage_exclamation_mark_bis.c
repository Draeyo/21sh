/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_exclamation_mark_bis.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:00:22 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 12:00:22 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		error_em(char *arg, char *sh_name)
{
	ft_printf("\n%s: !%s: event not found\n", sh_name, arg ? arg : "");
	strfree(&arg);
	return (-1);
}

int		manage_double_excl_mark(t_env *e, int *curr_pos)
{
	int	i_hist;

	if (!e->history)
		return (error_em("!", SH_NAME));
	i_hist = ft_tablen(e->history) - 1;
	do_substitution(&e->line, curr_pos, e->history[i_hist], 1);
	return (1);
}

int		join_line(t_env *e, int *curr_pos)
{
	char	*new;

	new = ft_strnew(*curr_pos + 1);
	new = ft_strncpy(new, e->line, *curr_pos);
	do_substitution_no_esc(&e->line, curr_pos, new, 2);
	strfree(&new);
	return (1);
}
