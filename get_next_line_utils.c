/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:46:27 by flauweri          #+#    #+#             */
/*   Updated: 2025/12/04 14:04:23 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_bzero(char	*line, char *buf)
{
	int	i;

	i = 0;
	if (line != NULL)
		free(line);
	while (i < BUFFER_SIZE)
		buf[i++] = 0;
	return (NULL);
}
