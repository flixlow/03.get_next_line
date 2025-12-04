/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:46:27 by flauweri          #+#    #+#             */
/*   Updated: 2025/12/03 18:00:57 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char	*str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char *buf)
{
	int		i;
	int		j;
	char	*newline;

	i = 0;
	j = 0;
	newline = malloc(ft_strlen(line, '\0') + ft_strlen(buf, '\n') + 2);
	if (newline == NULL)
		return (NULL);
	while (line != NULL && line[i])
	{
		newline[i] = line[i];
		i++;
	}
	while (buf[j] && buf[j] != '\n')
		newline[i++] = buf[j++];
	if (buf[j] == '\n')
		newline[i++] = '\n';
	newline[i] = 0;
	if (line != NULL)
		free(line);
	return (newline);
}

void	ft_memmove(char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] && buf[i] == '\n')
	{
		i++;
		while (buf[i])
			buf[j++] = buf[i++];
	}
	buf[j] = 0;
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			bytes;

	line = NULL;
	i = 0;
	bytes = 0;
	if (buf[0] != 0)
	{
		while (buf[i] && buf[i] != '\n')
			i++;
		if (buf[i] == '\0')
		{
			line = ft_strjoin(line, buf);
			buf[0] = 0;
			i = 0;
		}
		else if (buf[i] == '\n')
		{
			line = ft_strjoin(line, buf);
			ft_memmove(buf);
		}
	}
	while (buf[0] == 0 && buf[i] != '\n')
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == (-1))
			return (0);
		if (bytes != BUFFER_SIZE)
			return (ft_strjoin(line, buf));
		buf[bytes] = '\0';
		while (buf[i] && buf[i] != '\n')
			i++;
		if (buf[i] == '\0')
		{
			line = ft_strjoin(line, buf);
			buf[0] = 0;
			i = 0;
		}
		else if (buf[i] == '\n')
		{
			line = ft_strjoin(line, buf);
			ft_memmove(buf);
		}
	}
	return (line);
}

/*erreur pour fin de document bytes[BUFFER_SIZE], 
il peut y avoir encore des \n dans cette fin de documents*/