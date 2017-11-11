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

static int		ft_str_word_len(const char *str, char del)
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

static size_t	ft_wc(const char *str, char delim)
{
	size_t	wc;
	int		i;

	wc = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != delim && (str[i - 1] == delim || str[i - 1] <= 0))
			wc++;
		i++;
	}
	return (wc + 1);
}

static char		*ft_trim(char *str, char del, int flag)
{
	while (*str == del && flag)
		str++;
	while (*str != del && !flag)
		str++;
	return (str);
}

static char		*ft_str_cpy(char *dest, char *src, char del)
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

char			**ft_strsplit(char const *s, char c)
{
	char	**result;
	char	*tmp;
	size_t	i;

	if (s && (result = (char**)malloc(sizeof(char*) * ft_wc(s, c))))
	{
		i = -1;
		tmp = (char*)s;
		while (++i < (ft_wc((char*)s, c) - 1))
		{
			tmp = ft_trim(tmp, c, 1);
			if (!(result[i] = (char*)malloc(ft_str_word_len(tmp, c) + 1)))
			{
				while (--i)
					ft_strdel(&result[i]);
				free(result);
				return (NULL);
			}
			result[i] = ft_str_cpy(result[i], tmp, c);
			tmp = ft_trim(tmp, c, 0);
		}
		result[i] = 0;
		return (result);
	}
	return (NULL);
}
