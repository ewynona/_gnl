/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:40:48 by asumerag          #+#    #+#             */
/*   Updated: 2020/11/13 15:45:41 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*input;
	int			bts_read;

	bts_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || !(line) ||
		!(buff = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while (end_line(input) && bts_read)
	{
		bts_read = read(fd, buff, BUFFER_SIZE);
		if (bts_read < 0)
		{
			free(buff);
			return (-1);
		}
		buff[bts_read] = '\0';
		input = ft_strjoin(input, buff);
	}
	free(buff);
	*line = new_str(input);
	input = next_str(input);
	if (bts_read == 0)
		return (0);
	return (1);
}
