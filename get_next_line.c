/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:01:55 by wvallee           #+#    #+#             */
/*   Updated: 2022/12/07 15:36:36 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_substr_free(char *s, unsigned int start, size_t len, char *rest)
{
	size_t	truth;
	char	*dest;
	size_t	count;

	if (s != NULL)
	{
		count = 0;
		truth = len;
		if (ft_strlen(s + start) < len)
			truth = ft_strlen(s + start);
		dest = (char *)malloc((truth + 2) * sizeof(char));
		if (dest == NULL)
			return (NULL);
		ft_bzero(dest, truth + 2);
		while (count < truth)
		{
			dest[count] = s[start];
			count++;
			start++;
		}
	}
	else
		dest = NULL;
	free(rest);
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*fusion;

	len1 = 0;
	len2 = 0;
	fusion = NULL;
	if (s1 != NULL || s2 != NULL)
	{
		if (s1 != NULL)
			len1 = ft_strlen(s1);
		if (s2 != NULL)
			len2 = ft_strlen(s2);
		fusion = (char *)malloc((len1 + len2) + 1 * sizeof(char));
		if (fusion == NULL)
			return (NULL);
		ft_bzero(fusion, len1 + len2 + 1);
		if (s1 != NULL)
			ft_strlcpy(fusion, s1, len1 + 1);
		if (s2 != NULL)
			ft_strlcpy(&fusion[len1], s2, len2 + 1);
	}
	free(s1);
	return (fusion);
}

char	*dest_origin(char *dest, int fd)
{
	ssize_t		bytes_read;
	char		*temp;

	temp = NULL;
	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	while (-1 == ft_strchr_index(dest, '\n'))
	{
		ft_bzero(temp, BUFFER_SIZE + 1);
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		dest = ft_strjoin(dest, temp);
	}
	free(temp);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*rest = NULL;
	char		*dest;
	int			i;
	int			len;

	i = 0;
	dest = NULL;
	if (ft_strlen(rest) > 0)
	{
		while (rest[i] != '\n' && rest[i])
			i++;
		dest = ft_substr_free(rest, 0, i + 1, dest);
		rest = ft_substr_free(rest, i + 1, ft_strlen(rest), rest);
	}
	if (-1 < ft_strchr_index(dest, '\n'))
		return (dest);
	dest = dest_origin(dest, fd);
	if (-1 < ft_strchr_index(dest, '\n')
		&& (unsigned int)ft_strchr_index(dest, '\n') + 1 != ft_strlen(dest))
	{
		len = ft_strlen(dest);
		rest = ft_substr_free(dest, ft_strchr_index(dest, '\n') + 1, len, rest);
		dest = ft_substr_free(dest, 0, ft_strchr_index(dest, '\n') + 1, dest);
	}
	return (dest);
}
