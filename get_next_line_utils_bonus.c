/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:39:35 by flauweri          #+#    #+#             */
/*   Updated: 2025/12/10 13:39:39 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
