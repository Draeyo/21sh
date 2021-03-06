/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 11:59:20 by vlistrat          #+#    #+#             */
/*   Updated: 2017/04/14 13:03:38 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_env_error(char *cmd)
{
	ft_error("env", "illegal option --", cmd);
	ft_error("usage", "env [-i name1=val1 ...] [-u name]", NULL);
	return (-1);
}

void	ft_env_bis(t_env *e, char ***env_cpy, char **cmd, int i)
{
	char	**tmp;

	tmp = NULL;
	while (ft_strchr(cmd[i], '='))
	{
		tmp = *env_cpy;
		if (!(*env_cpy = ft_tabcat(*env_cpy, cmd[i++])))
			break ;
		ft_free_tab(tmp);
	}
	e->env = *env_cpy;
	if (cmd[i])
	{
		e->env_exec = 1;
		i = ft_exec_cmd(e, &cmd[i]);
	}
	else
		ft_puttab(e->env);
}
