/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:34:41 by mea               #+#    #+#             */
/*   Updated: 2021/10/22 11:30:24 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*new;
	unsigned char	src;
	size_t			i;

	src = c;
	new = b;
	i = 0;
	while (i < len)
	{
		new[i++] = src;
	}
	return (b);
}
