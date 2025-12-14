/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:59:14 by flauweri          #+#    #+#             */
/*   Updated: 2025/12/13 08:46:06 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char	*str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == '\n')
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
	newline = malloc(ft_strlen(line, '\0') + ft_strlen(buf, '\n') + 1);
	if (newline == NULL)
		return (ft_bzero(line, buf));
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

char	*searching_n(char *line, char *buf, int *i)
{
	while (buf[*i] && buf[*i] != '\n')
		(*i)++;
	if (buf[*i] == '\0')
	{
		line = ft_strjoin(line, buf);
		if (!line)
			return (NULL);
		buf[0] = 0;
		(*i) = 0;
	}
	else if (buf[*i] == '\n')
	{
		line = ft_strjoin(line, buf);
		if (!line)
			return (NULL);
		ft_memmove(buf);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[FD_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			bytes;
	int			i;

	line = NULL;
	i = 0;
	if (fd >= FD_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buf[fd][0] != 0)
		line = searching_n(line, buf[fd], &i);
	while (buf[fd][0] == 0 && buf[fd][i] != '\n')
	{
		bytes = read(fd, buf[fd], BUFFER_SIZE);
		if (bytes == -1)
			return (ft_bzero(line, buf[fd]));
		buf[fd][bytes] = '\0';
		if (bytes == 0)
			return (line);
		else if ((bytes < BUFFER_SIZE && BUFFER_SIZE > 1)
			|| (BUFFER_SIZE == 1 && buf[fd][0] == '\n'))
			return (searching_n(line, buf[fd], &i));
		line = searching_n(line, buf[fd], &i);
	}
	return (line);
}
