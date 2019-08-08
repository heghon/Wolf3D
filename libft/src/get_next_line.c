/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseneca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:22:59 by sseneca           #+#    #+#             */
/*   Updated: 2019/04/03 14:24:13 by sseneca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int			ft_check(char **stat, char **line)
{
	char			*tmp;

	tmp = ft_strchr(*stat, '\n');
	if (tmp)
	{
		*line = ft_strsub(*stat, 0, tmp - *stat);
		ft_memmove(*stat, tmp + 1, ft_strlen(tmp));
		tmp = NULL;
		return (1);
	}
	return (0);
}

static	int			ft_read(int fd, char **stat, char **line)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;
	char			*tmp;

	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		tmp = NULL;
		if (*stat)
		{
			tmp = ft_strdup(*stat);
			ft_memdel((void **)stat);
			*stat = ft_strjoin(tmp, buff);
			ft_memdel((void **)&tmp);
		}
		else
			*stat = ft_strdup(buff);
		if (ft_check(stat, line))
			return (1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static	char	*stat[OPEN_MAX];
	int				read;

	if (!line || 0 > fd || fd >= OPEN_MAX)
		return (-1);
	if (stat[fd] && ft_check(&stat[fd], line))
		return (1);
	read = ft_read(fd, &stat[fd], line);
	if (read != 0)
		return (read);
	if (stat[fd] == NULL || stat[fd][0] == '\0')
		return (0);
	*line = stat[fd];
	stat[fd] = NULL;
	return (1);
}
