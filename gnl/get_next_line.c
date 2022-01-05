/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:18:47 by mea               #+#    #+#             */
/*   Updated: 2021/11/22 11:55:13 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_save(int fd, char *save)
{
	char		buff[BUFF_SIZE + 1];
	int			nbo;

		nbo = 1;
	while (!ft_strchr(save, '\n') && nbo != 0)
	{
		nbo = read(fd, buff, BUFF_SIZE);
		if (nbo == -1)
			return (NULL);
		buff[nbo] = '\0';
		save = ft_strjoin(save, buff);
	}
	return (save);
}

char	*get_buff_1st_line(char *save)
{
	char	*str;
	int		i;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_buff_2nd_part(char *save)
{
	char	*tmp;
	char	*new_save;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tmp = save;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	if (tmp[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	new_save = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!new_save)
		return (NULL);
	i++;
	while (tmp[i])
		new_save[j++] = tmp[i++];
	new_save[j] = '\0';
	free(save);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*str;

	if (fd < 0 || BUFF_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!save)
	{
		save = malloc(sizeof(char) * 1);
		save[0] = '\0';
	}
	if (!save)
		return (NULL);
	save = ft_get_save(fd, save);
	str = get_buff_1st_line(save);
	save = get_buff_2nd_part(save);
	if (!str || str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	return (str);
}
