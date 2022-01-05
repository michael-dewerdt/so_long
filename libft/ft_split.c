/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:11:21 by mea               #+#    #+#             */
/*   Updated: 2021/10/26 16:01:00 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_free(char **str, int size)
{
	while (size--)
		free(str[size]);
	return (-1);
}

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == c || str[i + 1] == '\0') == 1
			&& (str[i] == c || str[i] == '\0') == 0)
			words++;
		i++;
	}
	return (words);
}

static void	ft_copy_word(char *dest, const char *from, char c)
{
	int	i;

	i = 0;
	while ((from[i] == c || from[i] == '\0') == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static int	ft_write_split(char **arr, const char *str, char c)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == c || str[i] == '\0') == 1)
			i++;
		else
		{
			j = 0;
			while ((str[i + j] == c || str[i + j] == '\0') == 0)
				j++;
			arr[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!arr)
				return (ft_free(arr, word - 1));
			ft_copy_word(arr[word], str + i, c);
			i = i + j;
			word++;
		}
	}
	return (0);
}

char	**ft_split(const char *str, char c)
{
	char	**arr;
	int		words;

	words = ft_count_words(str, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	arr[words] = 0;
	if (ft_write_split(arr, str, c) == -1)
		return (NULL);
	return (arr);
}
