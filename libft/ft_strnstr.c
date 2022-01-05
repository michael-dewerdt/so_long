/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:40:28 by mea               #+#    #+#             */
/*   Updated: 2021/10/26 16:05:53 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	if (!*s2)
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0' && (size_t)i < n)
	{
		if (s1[i] == s2[0])
		{
			j = 1;
			while (s2[j] != '\0' && s1[i + j] == s2[j] && (size_t)(i + j) < n)
				++j;
			if (s2[j] == '\0')
				return ((char *)&s1[i]);
		}
		++i;
	}
	return (0);
}
