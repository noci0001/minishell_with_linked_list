/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:04:19 by snocita           #+#    #+#             */
/*   Updated: 2023/06/24 16:31:48 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int is_red(char *str)
{
	if (*str == '<' && !str[1])
		return (1);
	if (*str == '>'  && !str[1])
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
	if (check_quantity_of_quotation(str) == 0)
		return (0);
	if (check_for_letters(str) == 0)
		return (0);
	return (1);
}

int check_for_letters(char *str)
{
	int found_status;

	found_status = 0;
	while (*str)
	{
		if (*str != '\'' || *str != '\"')
			found_status = 1;
		str++;
	}
	printf("%d\n", found_status);
	return (found_status);
}

char *remove_quotes(char *str)
{
	int i;
	int j;
	char *ret_str = malloc(sizeof(char *) * 100);
	if (!ret_str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == '\"' || str[i] == '\''))
			i++;
		// if (str[i] && ((str[i] != '\'') || (str[i] != '\"')))
		// 	ret_str[j++] = str[i++];
		while (str[i] && ((str[i] != '\'') || (str[i] != '\"')))
			ret_str[j++] = str[i++];
		printf("->%c\n", str[i]);
		if (str[i] && (str[i] == '\'' || str[i] == '\"'))
			break;
	}
	ret_str[j] = '\0';
	return (ret_str);
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
		return (0);
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
	if (words[1] && words[1][0] == '-' && words[1][1])
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
			words[i] = remove_quotes(words[i]);
			curr->args[j] = words[i];
			printf("IS ARG ->%s\n", curr->args[j]);
			j++;
		}
		i++;
	}
	return (curr);
}
