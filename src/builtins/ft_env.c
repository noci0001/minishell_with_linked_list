/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:21:22 by snocita           #+#    #+#             */
/*   Updated: 2023/06/26 18:24:34 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

extern char	**g_my_envp;

int	ft_env(char	**g_my_envp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g_my_envp[i])
		printf("%s\n", g_my_envp[i++]);
	return (1);
}
