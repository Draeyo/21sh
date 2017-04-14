/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:53:40 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:53:40 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		padding_left(t_struct *st, int limit)
{
	if (!(st->flags.pad & PAD_RIGHT))
		while (st->flags.width >= 0 && st->flags.width-- > limit)
			st->pc += ft_putchar_fd(st->flags.padchar, FD);
}

void		padding_right(t_struct *st, int limit)
{
	if (st->flags.pad & PAD_RIGHT)
		while (st->flags.width >= 0 && st->flags.width-- > limit)
			st->pc += ft_putchar_fd(st->flags.padchar, FD);
}
