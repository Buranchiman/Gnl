/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:02:48 by wvallee           #+#    #+#             */
/*   Updated: 2022/12/05 16:20:01 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	if (str != NULL)
	{	
		while (str[i] != '\0')
			i++;
	}
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (src)
	{
		while (src[i] != '\0' && (i + 1) < size)
		{
			dst[i] = src[i];
			i++;
		}
		if (size > 0)
			dst[i] = '\0';
		while (src[len] != '\0')
			len++;
	}
	return (len);
}

int	ft_index(const char *s, int c)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			if (s[i] == (unsigned char)c)
				return (i);
			i++;
		}
		if (s[i] == (unsigned char)(c))
			return (i);
	}
	return (-1);
}
