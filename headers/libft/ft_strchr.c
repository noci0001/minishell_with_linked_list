/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:02:23 by snocita           #+#    #+#             */
/*   Updated: 2023/01/11 12:04:42 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	Same as memchr but with 
	a character instead 
	of a byte

*/

char	*ft_strchr(const char *s, int c)
{
	if (c > 127)
		c = c % 128;
	while ((*s != '\0') && (*s != c) && s)
		s++;
	if (*s == c)
		return ((char *)s);
	return ((char *) NULL);
}

// int	main(void)
// {
// 	char	str[] = "HELLOOOO";

// 	printf("%s", ft_strchr(str, "H'));
// }
