/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:04:19 by snocita           #+#    #+#             */
/*   Updated: 2023/06/23 21:45:05 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int which_redirection(char *str)
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

int check_redirection_arg(char *word, int redirection)
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

t_cmd *lexing(char *block, t_cmd *curr)
{
	char **words_of_program;
	int type_redirection;
	int i;
	int j;

	i = 1;
	j = 0;
	debug_write("START OF NODE\n", 1);
	words_of_program = ft_split(block, ' ');
	if (words_of_program[0])
	{
		curr->cmd = words_of_program[0];
		printf("ADDED CMD: %s\n", curr->cmd);
	}
	if (words_of_program[1] && words_of_program[1][0] == '-' && words_of_program[1][1])
	{
		curr->flag = words_of_program[1];
		printf("ADDED FLAG: %s\n", curr->flag);
		i = 2;
	}
	while (words_of_program[i])
	{
		j = 0;

		type_redirection = which_redirection(words_of_program[i]);
		if (type_redirection != 0)
		{
			i++;
			check_redirection_arg(words_of_program[i], type_redirection);
		}
		else
		{
			words_of_program[i] = remove_quotes(words_of_program[i]);
			curr->args[j] = words_of_program[i];
			printf("CURR ARGS->%s\n", curr->args[0]);
			j++;
		}
		i++;
	}
	printf("END OF NODE\n");
	return (curr);
}
