/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalphanum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:36:48 by afarapon          #+#    #+#             */
/*   Updated: 2017/11/04 17:45:24 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalphanum(const char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (ft_isalnum(*str) || ft_isalpha(*str))
			str++;
		else
			return (0);
	}
	return (1);
}
