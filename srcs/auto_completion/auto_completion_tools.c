/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_completion_tools.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:12:48 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/07 14:12:49 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_is_dir(char *target)
{
	struct stat	s;
	int			ret;

	ret = 0;
	if (stat(target, &s) != -1)
	{
		if (S_ISDIR(s.st_mode))
			ret = 1;
	}
	return (ret);
}
