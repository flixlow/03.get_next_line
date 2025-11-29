/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:46:27 by flauweri          #+#    #+#             */
/*   Updated: 2025/11/29 14:09:45 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_free(char *s1, char *s2)
{
	
}

int	ft_strlen(char	*str)//strlen soit de l index du \n ou du \0
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	line = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (line == NULL)
		return (free(s1);
	while (s1[i])
	{
		line[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
		line[i++] = s2[j++];
	if (s2[j] != 0)
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*line;
	int				bytes;
	int				i;
	char			buf[BUFFER_SIZE];

	bytes = 0;
	while (1)
	{
		i = 0;
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == (-1))
			return (NULL);
		while (buf[i] && buf[i] != '\n')
			i++;
		if (buf[i] == '\n')
			return (ft_strjoin(line, buf));
		if (buf[i] == '\0')
			line = ft_strjoin(line, buf);
	}
	return (line);
}

int	main(int ac,char **av)
{
	int	fd;

	if (ac < 2)
		return (write(2, "File name missing.\n", 19));
	if (ac > 2)
		return (write(2, "Too many arguments.\n", 20));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		write (2, "Cannot read file.\n", 18);
		return (1);
	}
	__builtin_printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
