/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xword.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:56:58 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:56:58 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_xword_locate(int x, char *str, char div)
{
	int			n;
	int			i;

	n = 1;
	i = -1;
	while (str[++i] && n < x)
		if (str[i] == div)
			++n;
	if (n != x)
		return (-1);
	return (i);
}

char			*ft_xword(char *str, int x, char div)
{
	int			i;
	int			j;
	char		*word;

	i = -1;
	word = NULL;
	if ((i = ft_xword_locate(x, str, div)) < 0)
		return (NULL);
	j = i;
	while (str[j] && str[j] != div)
		++j;
	word = ft_strndup(&str[i], ft_abs(j - i));
	return (word);
}
