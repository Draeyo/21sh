/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:53:10 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:53:10 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print(t_struct *st, int ret)
{
	while (*st->format)
	{
		if (*st->format == '%')
		{
			++st->format;
			reset_lmod(st);
			if (*st->format == '\0')
				break ;
			parse_flags(st);
			if (parse_lenght_modifier(st))
				++st->format;
			ret = parse_args(st);
			if (ret)
			{
				++st->pc;
				ret = 0;
			}
		}
		else
			st->pc += ft_putchar_fd(*st->format, FD);
		reset_flags(st);
		++st->format;
	}
}

int				ft_printfd(int fd, const char *format, ...)
{
	t_struct	*st;
	int			pc;

	if ((st = malloc(sizeof(t_struct))) == NULL)
		return (0);
	FD = fd;
	va_start(st->args, format);
	set_init_st(st, format);
	ft_print(st, 0);
	va_end(st->args);
	pc = st->pc;
	free(st);
	return (pc);
}

int				ft_printf(const char *format, ...)
{
	t_struct	*st;
	int			pc;

	if ((st = malloc(sizeof(t_struct))) == NULL)
		return (0);
	FD = 1;
	va_start(st->args, format);
	set_init_st(st, format);
	ft_print(st, 0);
	va_end(st->args);
	pc = st->pc;
	free(st);
	return (pc);
}
