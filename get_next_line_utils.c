/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:46:27 by flauweri          #+#    #+#             */
/*   Updated: 2025/11/26 17:06:02 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_substr(char *s, unsigned int start, size_t len)
{
	size_t    i;
	char	*dest;

	i = 0;
	dest = malloc (sizeof(char) * len + 1);
	if (dest == 0)
		return (0);
	while (s[start] && len > 0)
	{
		dest[i++] = s[start++];
		len--;
	}
	dest[i] = 0;
	return (dest);
}
