/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:27:41 by mea               #+#    #+#             */
/*   Updated: 2021/10/28 16:25:56 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list			*curr;

	curr = lst;
	if (!lst || !curr)
		return (NULL);
	while (curr->next)
	{
		curr = curr->next;
	}
	return (curr);
}
