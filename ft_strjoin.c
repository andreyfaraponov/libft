/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 16:14:03 by afarapon          #+#    #+#             */
/*   Updated: 2017/10/28 16:14:04 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	result = ft_strnew(ft_strlen((char*)s1) + ft_strlen((char*)s2));
	if (result == NULL)
		return (NULL);
	result = ft_strcat(result, (char*)s1);
	result = ft_strcat(result, (char*)s2);
	return (result);
}
