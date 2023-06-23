/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:14:35 by snocita           #+#    #+#             */
/*   Updated: 2023/01/09 13:33:32 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

/*

	What are you even doing if you don't know this one?

*/

size_t	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (*s)
	{
		s++;
		length += 1;
	}
	return (length);
}
