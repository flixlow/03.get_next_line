/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauweri <flauweri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:46:27 by flauweri          #+#    #+#             */
/*   Updated: 2025/12/12 09:19:04 by flauweri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*ft_substr(char *line);
char	*ft_strjoin(char *line, char *buf);
int		ft_free(char *s1, char *s2);
int		ft_strlen(char	*str, char c);
void	ft_memmove(char *buf);
void	*ft_bzero(char	*line, char *buf);

#endif