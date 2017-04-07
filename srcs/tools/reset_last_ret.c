/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_last_ret.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:23:33 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/07 14:23:34 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	reset_last_ret(t_env *e, int ret)
{
	strfree(&e->last_ret);
	e->last_ret = ft_xtoa(ret);
}
