/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 16:14:20 by afarapon          #+#    #+#             */
/*   Updated: 2017/10/29 15:40:36 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char			*result;
	unsigned int	i;

	i = 0;
	if ((result = ft_strdup((char*)s)) == NULL)
		return (NULL);
	if (!s)
		return (NULL);
	while (result[i])
	{
		result[i] = f(result[i]);
		i++;
	}
	return (result);
}
