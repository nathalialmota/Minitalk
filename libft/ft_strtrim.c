/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nade-lim <nade-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:26:26 by nade-lim          #+#    #+#             */
/*   Updated: 2024/11/10 10:50:53 by nade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_is_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*result_str;

	start = 0;
	end = ft_strlen(s1);
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[start] && ft_char_is_in_set(s1[start], set))
		start++;
	if (start < end)
	{
		while (start < end && ft_char_is_in_set(s1[end - 1], set))
			end--;
	}
	len = end - start;
	result_str = malloc(len + 1);
	if (result_str == NULL)
		return (NULL);
	ft_memcpy(result_str, &s1[start], len);
	result_str[len] = '\0';
	return (result_str);
}
