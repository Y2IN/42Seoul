/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:09:31 by yje               #+#    #+#             */
/*   Updated: 2022/08/18 14:14:13 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_line(int fd, char *buffer, char *backup)
{
	int		readsize;
	char	*tmp;

	while (1)
	{
		readsize = read(fd, buffer, BUFFER_SIZE);
		if (readsize == -1)
			return (0);
		else if (readsize == 0)
			break ;
		buffer[readsize] = '\0';
		if (!backup)
			backup = ft_strdup("");
		tmp = backup;
		backup = ft_strjoin(tmp, buffer);
		if (!backup)
			return (NULL);
		if (backup[0] == '\0')
			return (NULL);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (backup);
}

static char	*cut_back(char *backup)
{
	int		i;
	char	*res;

	i = 0;
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	if (backup[i] == '\0')
		return (0);
	res = ft_substr(backup, i + 1, ft_strlen(backup) - i);
	if (!res)
		return (NULL);
	if (res[0] == '\0')
	{
		free(res);
		res = NULL;
		return (NULL);
	}
	backup[i + 1] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*backup[OPEN_FD_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_FD_MAX)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = read_line(fd, buffer, backup[fd]);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		free(backup[fd]);
		backup[fd] = NULL;
		return (NULL);
	}
	backup[fd] = cut_back(line);
	return (line);
}
