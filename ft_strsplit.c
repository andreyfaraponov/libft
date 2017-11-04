/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 16:15:04 by afarapon          #+#    #+#             */
/*   Updated: 2017/10/29 19:29:55 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_word_len(char *str, char del)
{
	int		len;

	len = 0;
	while (*str && *str != del)
	{
		len++;
		str++;
	}
	return (len);
}

static int	ft_wc(char *str, char delim)
{
	int		wc;
	int		i;

	wc = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != delim && (str[i - 1] == delim || str[i - 1] <= 0))
			wc++;
		i++;
	}
	return (wc);
}

static char	*ft_trim(char *str, char del, int flag)
{
	while (*str == del && flag)
		str++;
	while (*str != del && !flag)
		str++;
	return (str);
}

static char	*ft_str_cpy(char *dest, char *src, char del)
{
	char	*res;

	res = dest;
	while (*src && *src != del)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**result;
	char	*tmp;
	size_t	i;
	size_t	wc;

	if (s)
	{
		wc = ft_wc((char*)s, c);
		if ((result = (char**)malloc(sizeof(char*) * (wc + 1))) == NULL)
			return (NULL);
		i = -1;
		tmp = (char*)s;
		while (++i < wc)
		{
			tmp = ft_trim(tmp, c, 1);
			if ((result[i] = (char*)malloc(ft_str_word_len(tmp, c) + 1))
			== NULL)
				return (NULL);
			result[i] = ft_str_cpy(result[i], tmp, c);
			tmp = ft_trim(tmp, c, 0);
		}
		result[i] = 0;
		return (result);
	}
	return (NULL);
}
