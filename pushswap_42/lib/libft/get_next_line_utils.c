/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:58:12 by athirion          #+#    #+#             */
/*   Updated: 2021/12/07 09:58:50 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i ++;
	if (str[i] == '\n')
		i ++;
	return (i);
}

int	ft_is_nl(char *str)
{
	int	index;

	index = 0;
	while (str && str[index])
	{
		if (str[index] == '\n')
			return (1);
		index ++;
	}
	return (0);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		substr = (char *)malloc(sizeof(char) * 1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
	}
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[start + i];
		i ++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t		i;
	char		*str;

	if (!s1)
		return (ft_substr_gnl(s2, 0, ft_strlen(s2)));
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	i = -1;
	while (s2[++i])
		str[i + ft_strlen(s1)] = s2[i];
	str[i + ft_strlen(s1)] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}
