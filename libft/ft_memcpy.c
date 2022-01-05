/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:42:33 by mea               #+#    #+#             */
/*   Updated: 2021/10/26 14:59:34 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char	*cps1;
	unsigned char	*cps2;

	cps1 = (unsigned char *) s1;
	cps2 = (unsigned char *) s2;
	if (!cps1 && !cps2)
		return (NULL);
	while (n > 0)
	{
		*cps1++ = *cps2++;
		n--;
	}
	return (s1);
}
