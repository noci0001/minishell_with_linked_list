/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:04:19 by snocita           #+#    #+#             */
/*   Updated: 2023/06/28 15:56:31 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	which_redirection(char *str)
{
	if (*str == '<')
		return (1);
	if (*str == '>')
		return (2);
	if (!str[1])
		return (0);
	if (str[0] == '<' && str[1] == '<')
		return (3);
	if (str[0] == '>' && str[1] == '>')
		return (4);
	return (0);
}

int	check_redirection_arg(char *word, int redirection)
{
	if (redirection == 1)
		redirection_in(word);
	if (redirection == 2)
		redirection_out(word);
	if (redirection == 3)
		here_doc(word);
	if (redirection == 4)
		double_redirection(word);
	return (0);
}

t_cmd	*lexing(char *segmented_input, t_cmd *curr)
{
	char	**words_of_program;
	int		type_redirection;
	int		i;
	int		j;

	j = 0;
	type_redirection = 0;
	debug_get_sectioned_input(segmented_input);
	words_of_program = ft_split(segmented_input, ' ');
	// remove_quote(words_of_program);
	if (words_of_program[0])
	{
		free(curr->cmd);
		curr->cmd = ft_strdup(words_of_program[0]);
		debug_write("CMD intercepted: ", 0);
		debug_write(curr->cmd, 1);
	}
	i = 1;
	if (words_of_program[1] && words_of_program[1][0] == '-' \
		&& words_of_program[1][1])
	{
		curr->flag = ft_strdup(words_of_program[1]);
		debug_write("FLAG intercepted: ", 0);
		debug_write(curr->flag, 1);
		i = 2;
	}
	j = 0;
	if (words_of_program[i])
	{
		curr->args = allocate_args(words_of_program, i);
		while (words_of_program[i])
		{
			debug_write("ARG intercepted: ", 0);
			debug_write(words_of_program[i], 1);
			curr->args[j++] = words_of_program[i++];
		}
		curr->args[j] = NULL;
	}
	free_double_arr(words_of_program);
	return (curr);
}

char	**allocate_args(char **words_of_program, int i)
{
	int		j;
	char	**args;

	j = i;
	while (words_of_program[i])
		i++;
	args = malloc(sizeof(char *) * (i - j + 1));
	return (args);
}
