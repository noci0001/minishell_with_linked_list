/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:21:14 by snocita           #+#    #+#             */
/*   Updated: 2023/06/25 16:50:45 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// printf
#include <stdlib.h>
#include <string.h>
// malloc, free
#include <unistd.h>

char	**g_my_envp = NULL;

typedef struct s_cmd
{
	char	**g_my_envp;
}	t_cmd;

int	ft_export(char *to_export);
char	**obtain_double_array(char **double_array);
char	**obtain_envp(char **envp);
char	*check_string_to_export(char	*to_export);
//TEMPORARY

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
		ret[i] = malloc(sizeof(char) * (strlen(double_array[i]) + 1));
		if (!ret[i])
			return (NULL);
		//convert to user lib function (ft_)
		strlcpy(ret[i], double_array[i], (strlen(double_array[i]) + 1));
		i++;
	}
	return (ret);
}

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t				i;
	const unsigned char	*st1;
	const unsigned char	*st2;

	i = 0;
	st1 = (const unsigned char *) str1;
	st2 = (const unsigned char *) str2;
	while ((i < num) && ((*st1 != '\0') || (*st2 != '\0')))
	{
		if (*st1 == *st2)
		{
			st1++;
			st2++;
			i++;
		}
		else
		{
			return (*st1 - *st2);
		}
	}
	return (0);
}

//END TEMPORARY

char	**obtain_envp(char **envp)
{
	char	**g_my_envp;

	g_my_envp = obtain_double_array(envp);
	return (g_my_envp);
}

int	check_for_duplicates(char	*to_export)
{
	int	i;

	i = 0;
	while (g_my_envp[i])
	{
		if (ft_strncmp(g_my_envp[i], to_export, strlen(to_export)) == 0)
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
	if (to_export[0] == '=' || (to_export[strlen(to_export) - 1] == '='))
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

void	free_double_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_export(char *to_export)
{
	check_string_to_export(to_export);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	g_my_envp = obtain_envp(envp);
	ft_export("hello=there");
	ft_export("TERM=xterm-256color");
	ft_export("=there");
	ft_export("there=");
	ft_export("hello==there");
	free_double_arr(g_my_envp);
	return (0);
}
