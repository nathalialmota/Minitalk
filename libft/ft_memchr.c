/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nade-lim <nade-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:05:04 by nade-lim          #+#    #+#             */
/*   Updated: 2024/11/10 10:48:07 by nade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;
	char	c2;
	size_t	i;

	ptr = (char *)s;
	c2 = (char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == c2)
		{
			return ((void *) ptr + i);
		}
		i++;
	}
	return (NULL);
}
