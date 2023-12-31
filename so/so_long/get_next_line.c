/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:47:14 by faata             #+#    #+#             */
/*   Updated: 2023/11/02 15:28:02 by faata            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*refill(int fd, char *buffer)
{
	char	*temp;
	int		byte_readed;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	byte_readed = 1;
	while (!ft_strchr(buffer, '\n') && byte_readed)
	{
		byte_readed = read(fd, temp, BUFFER_SIZE);
		if (byte_readed == -1)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		temp[byte_readed] = 0;
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char	*get_line_ssd(char *buffer)
{
	size_t		i;
	char		*res;

	i = 0;
	if (buffer[i] == 0)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		res = malloc(sizeof(char) * (i + 2));
	else
		res = malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		(void)((res[i] = buffer[i]) && (i++, 1));
	if (buffer[i] == '\n')
		(void)((res[i] = buffer[i]) && (i++, 1));
	res[i] = 0;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = refill(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line_ssd(buffer);
	buffer = cut_line(buffer, ft_strlen(line));
	return (line);
}

char	*cut_line(char *buffer, int len)
{
	char	*temp;
	size_t	i;

	if (buffer[len] == 0)
		return (free(buffer), NULL);
	temp = malloc((ft_strlen(buffer) - len + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (buffer[len])
		temp[i++] = buffer[len++];
	temp[i] = 0;
	free(buffer);
	return (temp);
}
