/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issticky.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:54:32 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:54:32 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/stat.h>

int			ft_issticky(char *path)
{
	struct stat	buf;

	if (lstat(path, &buf) == -1)
		return (0);
	if ((buf.st_mode & S_ISUID) || (buf.st_mode & S_ISGID))
		return (1);
	return (0);
}
