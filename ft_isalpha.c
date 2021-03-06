/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 16:10:53 by afarapon          #+#    #+#             */
/*   Updated: 2017/11/07 21:16:38 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122) ||
		(c >= 65 && c <= 90))
		return (1);
	return (0);
}
