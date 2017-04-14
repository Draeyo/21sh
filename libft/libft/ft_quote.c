/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:55:22 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:55:22 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_check_quote_bs(char c, char quote, int bs)
{
	if (quote == '\0' && !bs && (c == '\'' || c == '\"'))
		return (c);
	else if (c == quote && ((!bs && quote == '\"') || quote == '\''))
		return ('\0');
	return (quote);
}

char	ft_check_quote(char c, char quote)
{
	if (quote == '\0' && (c == '\'' || c == '\"'))
		return (c);
	else if (c == quote)
		return ('\0');
	return (quote);
}
