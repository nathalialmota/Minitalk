/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nade-lim <nade-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:25:53 by nade-lim          #+#    #+#             */
/*   Updated: 2024/11/10 10:49:20 by nade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_substr(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	*ft_copy_substr(char const *s, char c)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	ptr = malloc(sizeof(char) * (i + 1));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, i + 1);
	return (ptr);
}

static void	ft_free_str(char **str)
{
	char	**ptr;

	if (str == NULL)
		return ;
	ptr = str;
	while (*ptr)
		free(*(ptr++));
	free(str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	char	**ptr;

	len = ft_count_substr(s, c);
	ptr = ft_calloc(sizeof(char *), (len + 1));
	if (ptr == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		while (*s == c)
			s++;
		ptr[i] = ft_copy_substr(s, c);
		if (ptr[i] == NULL)
		{
			ft_free_str(ptr);
			return (NULL);
		}
		s += ft_strlen(ptr[i]);
	}
	ptr[i] = 0;
	return (ptr);
}
