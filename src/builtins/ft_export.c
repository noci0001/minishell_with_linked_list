/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:21:14 by snocita           #+#    #+#             */
/*   Updated: 2023/06/28 13:07:08 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char	**g_my_envp;

char	**obtain_double_array(char **double_array)
{
	char	**ret;
	int		i;

	i = 0;
	while (double_array[i])
		i++;
	ret = malloc(sizeof(char *) * (i + 1));
	if (!ret)
		return (NULL);
	ret[i] = (NULL);
	i = 0;
	while (double_array[i])
	{
		//convert to user lib function (ft_)
		ret[i] = malloc(sizeof(char) * (ft_strlen(double_array[i]) + 1));
		if (!ret[i])
			return (NULL);
		//convert to user lib function (ft_)
		strlcpy(ret[i], double_array[i], (ft_strlen(double_array[i]) + 1));
		i++;
	}
	return (ret);
}

char	**obtain_envp(char **envp)
{
	g_my_envp = obtain_double_array(envp);
	return (g_my_envp);
}

int	check_for_duplicates(char	*to_export)
{
	int	i;

	i = 0;
	while (g_my_envp[i])
	{
		if (ft_strncmp(g_my_envp[i], to_export, ft_strlen(to_export)) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_for_equal_and_letters(char	*to_export)
{
	int	i;
	int	equals_number;

	equals_number = 0;
	if (to_export[0] == '=' || (to_export[ft_strlen(to_export) - 1] == '='))
	{
		printf("Invalid exportation, discarding...\n");
		return (0);
	}
	i = 1;
	while (to_export[i])
	{
		if (to_export[i] == '=')
			equals_number++;
		if (equals_number > 1)
		{
			printf("Too many equals, discarding...\n");
			return (0);
		}
		i++;
	}
	return (1);
}

char	*check_string_to_export(char	*to_export)
{
	printf("STARTING STRING -> %s\n", to_export);
	if (check_for_equal_and_letters(to_export) == 1)
	{
		printf("Exported var has passed the lexical test!\n");
		if (check_for_duplicates(to_export) != 1)
		{
			printf("DUPLICATES FOUND, discarding...\n");
			return (0);
		}
		printf("TEST PASSED!\n");
	}
	return (to_export);
}

int	ft_export(char *to_export)
{
	check_string_to_export(to_export);
	return (1);
}

// int	main(int ac, char **av, char **envp)
// {
// 	(void)ac;
// 	(void)av;
// 	g_my_envp = obtain_envp(envp);
// 	ft_export("hello=there");//passes
// 	ft_export("TERM=xterm-256color");//not
// 	ft_export("=there");//not
// 	ft_export("there=");
// 	ft_export("hello==there");
// 	free_double_arr(g_my_envp);
// 	return (0);
// }
