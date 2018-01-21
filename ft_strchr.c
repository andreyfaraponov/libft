/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 16:13:11 by afarapon          #+#    #+#             */
/*   Updated: 2018/01/22 01:16:55 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strchr(const char *s, int c)
{
	unsigned char *tmp;
	unsigned char chr;

	chr = (unsigned char)c;
	tmp = (unsigned char*)s;
	if (!s)
		return (0);
	if (*tmp == chr)
		return ((char*)tmp);
	while (*tmp)
	{
		tmp++;
		if (*tmp == chr)
			return ((char*)tmp);
	}
	return (0);
}
