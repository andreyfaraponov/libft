/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:32:59 by afarapon          #+#    #+#             */
/*   Updated: 2018/01/22 01:24:37 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int		ft_reader(int fd, char **buf)
// {
// 	int		res;
// 	char	localbuf[BUFF_SIZE + 1];
// 	char	*tmp;

// 	if ((res = read(fd, localbuf, BUFF_SIZE)) == -1)
// 		return (-1);
// 	localbuf[res] = '\0';
// 	tmp = *buf;
// 	*buf = ft_strjoin(*buf, localbuf);
// 	if (!buf)
// 		return (-1);
// 	if (tmp && ft_strlen(tmp))
// 		free(tmp);
// 	return (res);
// }

// static int		ft_get_line(char **buf, char **line, char *tmp)
// {
// 	char	*forfree;
// 	int		i;

// 	i = *tmp == '\n' ? 1 : 0;
// 	*tmp = '\0';
// 	*line = ft_strdup(*buf);
// 	if (!i && ft_strlen(*buf) && (*buf = ft_strnew(1)))
// 		return (1);
// 	else if (!i && !ft_strlen(*buf))
// 	{
// 		free(buf);
// 		return (0);
// 	}
// 	forfree = *buf;
// 	*buf = ft_strdup(tmp + 1);
// 	free(forfree);
// 	return (1);
// }

// static t_reader	*ft_get_reader(int fd, t_reader **head)
// {
// 	t_reader	*tmp;
// 	t_reader	*new_reader;

// 	tmp = *head;
// 	while (tmp)
// 	{
// 		if (tmp->fd == fd)
// 			return (tmp);
// 		tmp = tmp->next;
// 	}
// 	new_reader = (t_reader*)malloc(sizeof(t_reader));
// 	new_reader->fd = fd;
// 	new_reader->buf = "";
// 	new_reader->next = *head;
// 	*head = new_reader;
// 	return (new_reader);
// }

// int				get_next_line(int fd, char **line)
// {
// 	static t_reader	*head = NULL;
// 	char			*temp;
// 	int				readres;
// 	t_reader		*current_reader;

// 	readres = 1;
// 	if (fd == -1 || !line || BUFF_SIZE < 1)
// 		return (-1);
// 	current_reader = ft_get_reader(fd, &head);
// 	while (line)
// 	{
// 		temp = current_reader->buf;
// 		while (*temp || !readres)
// 		{
// 			if (*temp == '\n' || !*temp)
// 				return (ft_get_line(&current_reader->buf, line, temp));
// 			temp++;
// 		}
// 		if ((readres = ft_reader(fd, &current_reader->buf)) == -1)
// 			return (-1);
// 	}
// 	return (0);
// }


static t_reader	*ft_get_reader(int fd, t_reader **head)
{
	t_reader	*tmp;
	t_reader	*new_reader;

	tmp = *head;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	new_reader = (t_reader*)malloc(sizeof(t_reader));
	new_reader->fd = fd;
	new_reader->buf = ft_strnew(0);
	new_reader->next = *head;
	*head = new_reader;
	return (new_reader);
}

static ssize_t	ft_line(char **str, char **line)
{
	char	*temp;

	if(*str && **str)
	{
		if (!ft_strchr(*str, '\n'))
		{
			if (!(*line = ft_strdup(*str)))
				return (-1);
			ft_strdel(str);
		}
		else
		{
			if (!(*line = ft_strsub(*str, 0,
				ft_strchr(*str, '\n') - *str)))
				return (-1);
			temp = *str;
			*str = ft_strdup((ft_strchr(*str, '\n')) + 1);
			ft_strdel(&temp);
		}
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_reader	*head = NULL;
	char 			buff[BUFF_SIZE + 1];
	char			*temp;
	ssize_t			ret;
	t_reader		*cur_read;

	if (fd == -1 || !line || BUFF_SIZE < 1)
		return (-1);
	cur_read = ft_get_reader(fd, &head);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		temp = cur_read->buf;
		cur_read->buf = ft_strjoin(cur_read->buf, buff);
		free(temp);
		if (ft_strchr(cur_read->buf, '\n'))
			break ;
	}
	ret = ft_line(&cur_read->buf, line);
	if (ret == -1)
		return (-1);
	return ((ret > 0) ? 1 : 0);
}
