/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:55:30 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 10:55:30 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int		a;

	a = 0;
	if (!s1 || !s2)
		return (-1);
	if (s1 && s2)
	{
		while (s1[a] == s2[a])
		{
			if (s1[a] == '\0' && s2[a] == '\0')
				return (0);
			a++;
		}
		return ((((unsigned char*)s1)[a] - (((unsigned char*)s2)[a])));
	}
	return (0);
}
