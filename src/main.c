/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:04:18 by snocita           #+#    #+#             */
/*   Updated: 2023/06/24 20:12:47 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void free_double_arr(char **str)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
	return ;
}

t_cmd	*malloc_node(void)
{
	t_cmd	*head;

	head = malloc(sizeof(t_cmd));
	if (!head)
		return (NULL);
	head->args = malloc(sizeof(char *) * 50);
	if (!(head->args))
		return (NULL);
	
	head->flag = NULL;
	head->cmd = NULL;
	head->fd = 0;
	head->next = NULL;
	return (head);
}

t_cmd	*create_linked_list(char *input)
{
	char	**program;
	int		i;
	t_cmd	*head;
	t_cmd	*curr;

	i = 0;
	// debug_get_full_input(input);
	program = ft_split(input, '|');
	head = malloc_node();
	curr = head;
	while (program[i])
	{
		curr = lexing(program[i], curr);
		curr->next = malloc_node();
		curr = curr->next;
		i++;
	}
	// debug_write("\nCLOSING...", 2);
	free_double_arr(program);
	return (head);
}

void	free_linked_list(t_cmd *head)
{
	t_cmd	*tmp;

	while (head != NULL)
	{
		tmp = head;
		if (head->args)
			free_double_arr(head->args);
		head = head->next;
		free(tmp);
	}
}

void	gate_function(char *input)
{
	if (check_quotation(input) != 1)
		return ;
	t_cmd *tmp = create_linked_list(input);
	free_linked_list(tmp);
	return ;
}

// from input detectc delimiters and implement a linked list
// accordingly so that each command points to its next
// delimeters -> '|', '>', '>>', '<', '<<'
// echo hello world | wc -l > text.txt
// "echo hello world wc -l > text.txt";
int main(void)
{
	char	*input;
	// ft_debug();

	printf("TO TEST -> echo -n hello there | cat -n | ls");
	input = readline("Minishelly$ ");
	if (strlen(input) > 0)
		add_history(input);
	gate_function(input);
	free(input);
	return (0);
}
