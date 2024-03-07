/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:05:33 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/07 16:10:43 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strrchr(char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = ft_strlen(str) + 1;
	while (i > 0)
	{
		i--;
		if (str[i] == (char)c)
			return (str + i);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}
