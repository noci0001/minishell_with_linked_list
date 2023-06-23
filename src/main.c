/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:04:18 by snocita           #+#    #+#             */
/*   Updated: 2023/06/23 21:09:44 by snocita          ###   ########.fr       */
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
	char **program;
	int i;
	t_cmd *head;
	t_cmd *curr;

	i = 0;
	printf("input is -> %s\n", input);
	program = ft_split(input, '|');
	printf("splitted input is -> %s\n", program[1]);
	head = malloc_node();
	curr = head;
	while (program[i])
	{
		printf("ANALIZYING STRING -> %s\n", program[i]);
		curr = lexing(program[i], curr);
		curr->next = malloc_node();
		curr = curr->next;
		i++;
	}
	curr = head;
	while (curr->next != NULL)
	{
		printf("!!ADDED NODE: %s\n", curr->cmd);
		curr = curr->next;
	}
	free_double_arr(program);
}

void gate_function(char *input)
{
	if (check_quotation(input) != 1)
		return;
	create_linked_list(input);
	return;
}

// from input detectc delimiters and implement a linked list
// accordingly so that each command points to its next
// delimeters -> '|', '>', '>>', '<', '<<'
// echo hello world | wc -l > text.txt
// "echo hello world wc -l > text.txt";
int main(void)
{
	char *input;
	ft_debug();

	input = readline("Minishelly$ ");
	if (strlen(input) > 0)
		add_history(input);
	gate_function(input);
	free(input);
	return (0);
}
