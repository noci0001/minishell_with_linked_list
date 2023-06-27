/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:30:59 by snocita           #+#    #+#             */
/*   Updated: 2023/06/27 15:05:30 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

extern char	**g_my_envp;

char	*ft_get_env(char	**envp, char	*value_to_fetch)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], value_to_fetch, \
			ft_strlen(value_to_fetch)) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

int	ft_pwd(void)
{
	char	*pwd;

	pwd = ft_get_env(g_my_envp, "PWD=");
	write(1, pwd, ft_strlen(pwd));
	return (1);
}
