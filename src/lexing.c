/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:04:19 by snocita           #+#    #+#             */
/*   Updated: 2023/06/22 19:05:56 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int is_red(char *str)
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

int check_quotation(char *str)
{
	printf("HERE2!\n");
	if (check_quantity_of_quotation(str) == 0)
		return (0);
	return (1);
}

int check_quantity_of_quotation(char *str)
{
	int scount;
	int dcount;

	scount = 0;
	dcount = 0;
	while (*str)
	{
		if (*str == '\'')
			scount++;
		if (*str == '\"')
			dcount++;
		str++;
	}
	if ((scount % 2 != 0) || (dcount % 2 != 0))
	{
		printf("ODD\n");
		return (0);
	}
	return (1);
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
	char **words = NULL;
	int type_redirection;
	int i;
	int j;

	i = 1;
	j = 0;
	words = ft_split(block, ' ');
	if (words[0])
		curr->cmd = words[0];
	if (words[1][0] == '-' && words[1][1] && words[1])
	{
		curr->flag = words[1];
		i = 2;
	}
	while (words[i])
	{
		j = 0;

		type_redirection = is_red(words[i]);
		if (type_redirection != 0)
		{
			i++;
			check_redirection_arg(words[i], type_redirection);
		}
		else
		{
			curr->args[j] = words[i];
			printf("IS ARG ->%s\n", curr->args[j]);
			j++;
		}
		i++;
	}
	return (curr);
}
