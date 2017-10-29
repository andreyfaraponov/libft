/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 16:14:52 by afarapon          #+#    #+#             */
/*   Updated: 2017/10/28 18:19:34 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char *begin;

	begin = (char*)s;
	while (*s)
		s++;
	while (s >= begin)
	{
		if (*s == c)
			return ((char*)s);
		s--;
	}
	return (0);
}
