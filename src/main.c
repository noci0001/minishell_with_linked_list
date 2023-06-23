/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:04:18 by snocita           #+#    #+#             */
/*   Updated: 2023/06/22 18:27:32 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void free_double_arr(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

t_cmd *malloc_node(void)
{
	t_cmd *head;

	head = malloc(sizeof(t_cmd *));
	if (!head)
		return (NULL);
	head->next = NULL;
	return (head);
}

void create_linked_list(char *input)
{
	char **ret;
	int i;
	t_cmd *head;
	t_cmd *curr;

	i = 0;
	ret = ft_split(input, '|');
	head = malloc_node();
	curr = head;
	while (ret[i])
	{
		curr = lexing(ret[i], curr);
		curr->next = malloc_node();
		curr = curr->next;
		i++;
	}
	free_double_arr(ret);
}

void gate_function(char *input)
{
	check_quotation(input);
	create_linked_list(input);
}

// from input detectc delimiters and implement a linked list
// accordingly so that each command points to its next
// delimeters -> '|', '>', '>>', '<', '<<'
// echo hello world | wc -l > text.txt
// "echo hello world wc -l > text.txt";
int main(void)
{
	char *input;

	input = readline("Minishelly$ ");
	if (strlen(input) > 0)
		add_history(input);
	gate_function(input);
	free(input);
	return (0);
}
