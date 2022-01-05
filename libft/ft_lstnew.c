/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:11:53 by mea               #+#    #+#             */
/*   Updated: 2021/10/28 12:50:47 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*cell;

	cell = (t_list *)malloc(sizeof(cell));
	if (!(cell))
		return (NULL);
	cell->content = content;
	cell->next = NULL;
	return (cell);
}
