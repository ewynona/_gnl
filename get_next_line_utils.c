/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:29:21 by gshona            #+#    #+#             */
/*   Updated: 2020/11/13 15:23:02 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#include <fcntl.h>

size_t	ft_strlen(char const *s)
{
	size_t i;

	i = 0;
	if (s)
		while (*s++)
			i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*str;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len1 + len2) + 1);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		str[i + len1] = s2[i];
		i++;
	}
	str[len1 + len2] = '\0';
	if (s1)
		free(s1);
	return (str);
}

int		end_line(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != '\n' && s[i] != '\0')
			i++;
		if (s[i] == '\n')
			return (0);
	}
	return (1);
}

char	*new_str(char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (0);
	while (s[i] != '\n' && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*next_str(char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	if (!(str = malloc(sizeof(char) * (ft_strlen(s) - i) + 1)))
	{
		free(s);
		return (NULL);
	}
	while (s[i + 1])
		str[j++] = s[1 + i++];
	str[j] = '\0';
	free(s);
	return (str);
}
