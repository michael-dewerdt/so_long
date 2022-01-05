/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:12:26 by mea               #+#    #+#             */
/*   Updated: 2021/10/27 14:12:39 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*ptr;

	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			ptr = ft_lstlast(*(alst));
			ptr->next = new;
		}
	}
}
