/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:13:48 by mea               #+#    #+#             */
/*   Updated: 2021/10/26 14:51:57 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_sign(long int nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

static long int	ft_len(int n)
{
	int					len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int		len;
	int		sign;
	char	*str;

	if (nbr < 0)
		sign = -1;
	else
		sign = 0;
	len = ft_len(nbr);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = '0' + ft_sign(nbr % 10);
		nbr = ft_sign(nbr / 10);
		len --;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
