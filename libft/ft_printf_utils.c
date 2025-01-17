/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nade-lim <nade-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:15:43 by nade-lim          #+#    #+#             */
/*   Updated: 2025/01/07 14:42:12 by nade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printint(int n)
{
	int		count;
	char	c;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_printint(n / 10);
	}
	c = n % 10 + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_printuint(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
	{
		count += ft_printuint(n / 10);
	}
	c = n % 10 + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_printhex_lower(unsigned long n)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count += ft_printhex_lower(n / 16);
	}
	write(1, &hex[n % 16], 1);
	count++;
	return (count);
}

int	ft_printhex_upper(unsigned long n)
{
	char	*hex;
	int		count;

	hex = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
	{
		count += ft_printhex_upper(n / 16);
	}
	write(1, &hex[n % 16], 1);
	count++;
	return (count);
}

int	ft_printptr(void *ptr)
{
	int				count;
	unsigned long	ptr2;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 0;
	ptr2 = (unsigned long)ptr;
	write(1, "0x", 2);
	count = ft_printhex_lower(ptr2);
	return (count + 2);
}
