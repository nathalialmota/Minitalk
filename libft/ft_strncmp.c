/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nade-lim <nade-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:42:45 by nade-lim          #+#    #+#             */
/*   Updated: 2024/11/10 10:50:31 by nade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char		c1;
	unsigned char		c2;
	size_t				i;

	i = 0;
	while (i < n)
	{
	c1 = (unsigned char)s1[i];
	c2 = (unsigned char)s2[i];
		if (c1 == '\0' || c2 == '\0')
		{
			return (c1 - c2);
		}
		if (c1 != c2)
		{
			return (c1 - c2);
		}
		i++;
	}
	return (0);
}
