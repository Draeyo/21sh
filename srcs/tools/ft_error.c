/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:01:25 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 12:01:25 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_error(char *util, char *msg, char *what)
{
	if (what && util && msg)
		ft_printfd(2, "%s: %s: %s: %s\n", SH_NAME, util, msg, what);
	else if (util && msg)
		ft_printfd(2, "%s: %s: %s\n", SH_NAME, util, msg);
	else if (msg)
		ft_printfd(2, "%s: %s\n", SH_NAME, msg);
	return (-1);
}
