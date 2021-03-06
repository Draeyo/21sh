/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:54:13 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:54:13 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_getnbr(const char *str)
{
	int		ret;

	ret = 0;
	if (str)
	{
		if (*str == '-')
			return (-ft_getnbr(&str[1]));
		while (*str >= '0' && *str <= '9')
		{
			ret = ret * 10 + (*str - '0');
			++str;
		}
	}
	return (ret);
}
