/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:04:19 by snocita           #+#    #+#             */
/*   Updated: 2023/06/24 20:14:22 by snocita          ###   ########.fr       */
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

t_cmd *lexing(char *segmented_input, t_cmd *curr)
{
	char	**words_of_program;
	char	*tmp;
	int		type_redirection;
	int		i;
	int		j;

	i = 1;
	j = 0;
	type_redirection = 0;
	// debug_get_sectioned_input(segmented_input);
	words_of_program = ft_split(segmented_input, ' ');
	if (words_of_program[0])
	{
		curr->cmd = words_of_program[0];
		// debug_write("CMD intercepted:", 0);
		// debug_write(curr->cmd, 1);
	}
	if (words_of_program[1] && words_of_program[1][0] == '-' && words_of_program[1][1])
	{
		curr->flag = words_of_program[1];
		// debug_write("FLAG intercepted:", 0);
		// debug_write(curr->flag, 0);
		i = 2;
	}
	while (words_of_program[i])
	{
		j = 0;
		tmp = remove_quotes(words_of_program[i]);
		curr->args[j] = ft_strdup(tmp);
		free(tmp);
		j++;
		i++;
	}
	free_double_arr(words_of_program);
	return (curr);
}
