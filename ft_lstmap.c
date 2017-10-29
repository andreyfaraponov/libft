/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 16:11:36 by afarapon          #+#    #+#             */
/*   Updated: 2017/10/29 15:14:43 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_deletelist(t_list *list)
{
	if (list)
	{
		free(list->content);
		free(list);
		list = NULL;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *tempnext;

	result = NULL;
	if (lst && !(result = f(lst)))
		return (NULL);
	lst = lst->next;
	tempnext = result->next;
	while (lst)
	{
		if ((tempnext = f(lst)))
			tempnext = tempnext->next;
		else
			ft_deletelist(tempnext);
		
		lst = lst->next;
	}
	return (result);
}
