/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:34:28 by obelair           #+#    #+#             */
/*   Updated: 2021/01/08 10:59:12 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/get_next_line.h"

char	*get_line(char *str)
{
	int		i;
	char	*tmp;

	if (!str)
		return (NULL);
	if ((i = ft_strichr(str, '\n')) == -1)
		tmp = ft_substr(str, 0, ft_strlen(str));
	else
		tmp = ft_substr(str, 0, i);
	return (tmp);
}

char	*get_keep_save(char *save)
{
	char	*keep;
	size_t	lenstr;
	int		i;

	i = ft_strichr(save, '\n');
	if (i == -1)
	{
		free(save);
		return (NULL);
	}
	lenstr = ft_strlen(save);
	keep = ft_substr(save, i + 1, lenstr - i);
	free(save);
	return (keep);
}

int		get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*save;
	int			rd;

	if ((fd < 0 || !line || BUFFER_SIZE < 1)
	|| !(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	rd = 1;
	while ((ft_strichr(save, '\n') == -1) && rd)
	{
		if ((rd = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[rd] = '\0';
		if (!(save = ft_strjoin(save, buff)))
			return (-1);
	}
	free(buff);
	if (!(*line = get_line(save)))
		return (-1);
	if (!(save = get_keep_save(save)) || !rd)
		return (0);
	return (1);
}
