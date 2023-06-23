/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:31:37 by snocita           #+#    #+#             */
/*   Updated: 2023/06/22 16:37:31 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_words(const char *array, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (array[i])
	{
		if (array[i] != c)
		{
			while (array[i] && array[i] != c)
				i++;
			counter++;
		}
		else
			i++;
	}
	return (counter);
}

static int	size_of_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	my_free(char **str, int j)
{
	while (j-- > 0)
		free(str[j]);
	free (str);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = -1;
	array = (char **)malloc(sizeof(char *) * (number_words(s, c) + 1));
	if (!array)
		return (NULL);
	while (++j < number_words(s, c))
	{
		while (s[i] == c)
			i++;
		size = size_of_word(s, c, i);
		array[j] = ft_substr(s, i, size);
		if (array[j] == NULL)
		{
			my_free(array, j);
			return (NULL);
		}
		i += size;
	}
	array[j] = 0;
	return (array);
}
