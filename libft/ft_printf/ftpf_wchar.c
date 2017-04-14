/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:53:55 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:53:55 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				a_wchar(t_struct *st)
{
	int			ret;

	ret = 0;
	st->stargs.wchar = (wchar_t)va_arg(st->args, wchar_t);
	st->flags.padchar = (st->flags.zero) ? '0' : ' ';
	padding_left(st, 1);
	if ((ret = handle_wchar(FD, st->stargs.wchar)) < 0)
		return ((st->pc = -1));
	st->pc += ret;
	padding_right(st, 1);
	return (0);
}
