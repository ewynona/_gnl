/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 16:58:00 by gshona            #+#    #+#             */
/*   Updated: 2020/11/13 03:23:28 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
int		end_line(char *s);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*new_str(char *s);
char	*next_str(char *s);

#endif
