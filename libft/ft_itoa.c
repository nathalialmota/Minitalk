/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nade-lim <nade-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:25:16 by nade-lim          #+#    #+#             */
/*   Updated: 2024/11/10 11:37:13 by nade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_calculate_digit_count(int num)
{
	unsigned int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		len = len + 1;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	number;
	unsigned int	len;
	char			*result_str;

	len = ft_calculate_digit_count(n);
	result_str = (char *)malloc((len + 1) * sizeof(char));
	if (result_str == NULL)
		return (NULL);
	if (n < 0)
	{
		result_str[0] = '-';
		number = -n;
	}
	else
		number = n;
	if (n == 0)
		result_str[0] = '0';
	result_str[len] = '\0';
	while (number != 0)
	{
		result_str[len - 1] = (number % 10) + '0';
		number = number / 10;
		len--;
	}
	return (result_str);
}
