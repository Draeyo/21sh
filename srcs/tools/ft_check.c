/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 11:00:05 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 11:00:05 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_last_char(t_env *e, char c)
{
	return (e->line && NB_READ >= 2 && e->line[NB_READ - 1] == c
			&& e->line[NB_READ - 2] != '\\');
}

int		check_prev_last_char(t_env *e, char c)
{
	return (e->line && NB_READ >= 2 && e->line[NB_READ - 2] == c
			&& e->line[NB_READ - 3] != '\\');
}
