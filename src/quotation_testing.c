/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotation_testing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:22:30 by snocita           #+#    #+#             */
/*   Updated: 2023/06/28 17:25:16 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// echo 'coco'
// echo 'coco \\ wow $ok'
// echo ' salut " hoho ''ok ok'
// echo ''
// cat ''
// echo ' ok ; wow ; cat ; ls ; echo $ok'

//echo "hello there how are you"
int	main(void)
{
	int		i;
	int		position_first_quote = 0;
	int		scount = 0;
	int		dcount = 0;
	char	*input = "echo \"hello 'there' 'how' are you\"";

	printf("Starting input -> %s\n", input);
	i = 0;
	while (input[i])
	{
		if (input[i] == '\"')
		{
			if (position_first_quote == 0)
				position_first_quote = i;
			dcount++;
		}
		else if (input[i] == '\'')
		{
			if (position_first_quote == 0)
				position_first_quote = i;
			scount++;
		}
		i++;
	}
	if (dcount != 0 && (dcount % 2 != 0))
	{
		printf("ODD number of quotes!\n");
		return (0);
	}
	if (scount != 0 && (scount % 2 != 0))
	{
		printf("ODD number of quotes!\n");
		return (0);
	}
	printf("The first quote is at position :%d\n", position_first_quote);
	printf("%c\n", input[position_first_quote]);

	printf("End input -> %s\n", input);
	return (0);
}

//replace input spaces with underscores

//echo_"hello_there_how_are_you"

//check number of quotes, if odd, STOP

//get address of first quote