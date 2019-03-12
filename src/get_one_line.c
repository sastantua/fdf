/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_one_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:14:47 by nivergne          #+#    #+#             */
/*   Updated: 2019/03/12 16:43:43 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_newline(char *store)
{
	int	i;

	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if (store[i] == '\n')
		return (i);
	else
		return (-1);
}

static char	*join_free(char *store, char *buff)
{
	int		i;
	int		j;
	char	*join;

	i = 0;
	j = 0;
	if (store)
		i = ft_strlen(store);
	if (buff)
		j = ft_strlen(buff);
	if (!(join = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	ft_memcpy(join, store, i);
	ft_memcpy(join + i, buff, j);
	join[i + j] = '\0';
	free(store);
	return (join);
}

static int	assign_line(char **store, char **buff, char **line)
{
	int		index;
	char	*tmp;

	*store = join_free(*store, *buff);
	index = find_newline(*store);
	if (index != -1)
	{
		tmp = *store;
		*line = ft_strsub(*store, 0, index);
		*store = ft_strdup(*store + index + 1);
		free(tmp);
		return (1);
	}
	return (0);
}

int			get_one_line(const int fd, char **line)
{
	int				ret;
	int				ret_2;
	char			*buff;
	static char		*store;

	store = NULL;
	buff = ft_strnew(32);
	if (!line || 32 <= 0 || (ret = read(fd, buff, 0)) < 0)
		return (-1);
	while ((ret = read(fd, buff, 32)) > 0)
	{
		ret_2 = assign_line(&store, &buff, line);
		ft_strdel(&buff);
		if (ret_2 == 1)
			return (1);
		buff = ft_strnew(32);
	}
	return (0);
}
