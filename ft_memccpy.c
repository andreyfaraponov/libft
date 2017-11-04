/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 16:11:54 by afarapon          #+#    #+#             */
/*   Updated: 2017/10/29 19:27:28 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c,
	size_t n)
{
	unsigned char *ddst;
	unsigned char *ssrc;

	ddst = (unsigned char*)dest;
	ssrc = (unsigned char*)src;
	while (n > 0)
	{
		*ddst = *ssrc;
		if (*ddst == (unsigned char)c)
			return ((void*)(ddst + 1));
		ddst++;
		ssrc++;
		n--;
	}
	return (0);
}
