/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:53:18 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:53:18 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				conversion_di(t_struct *st)
{
	if (st->lmod.j)
	{
		st->stargs.nbr = (long long)va_arg(st->args, long long);
	}
	else if (st->lmod.ll)
	{
		st->stargs.nbr = (long long)va_arg(st->args, long long);
	}
	else if (st->lmod.l || st->lmod.z)
	{
		st->stargs.nbr = (long)va_arg(st->args, long);
	}
	else if (st->lmod.hh)
	{
		st->stargs.nbr = (signed char)va_arg(st->args, int);
	}
	else if (st->lmod.h)
	{
		st->stargs.nbr = (short)va_arg(st->args, int);
	}
	else
	{
		st->stargs.nbr = (int)va_arg(st->args, int);
	}
	return (0);
}

int				conversion_oux(t_struct *st)
{
	if (st->lmod.j)
	{
		st->stargs.u_nbr = (long long)va_arg(st->args, long long);
	}
	else if (st->lmod.ll || st->lmod.z)
	{
		st->stargs.u_nbr = (unsigned long long)va_arg(st->args,
				unsigned long long);
	}
	else if (st->lmod.l)
	{
		st->stargs.u_nbr = (unsigned long)va_arg(st->args,
				unsigned long);
	}
	else if (st->lmod.hh)
	{
		st->stargs.u_nbr = (unsigned char)va_arg(st->args, int);
	}
	else if (st->lmod.h)
	{
		st->stargs.u_nbr = (unsigned short)va_arg(st->args, int);
	}
	else
		st->stargs.u_nbr = (unsigned int)va_arg(st->args, unsigned int);
	return (0);
}
