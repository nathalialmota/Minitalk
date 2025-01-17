/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nade-lim <nade-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:58:05 by nade-lim          #+#    #+#             */
/*   Updated: 2025/01/07 14:42:02 by nade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	count;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = 0;
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

int	ft_find_arg(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (format == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		count += ft_printptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		count += ft_printint(va_arg(args, int));
	else if (format == 'u')
		count += ft_printuint(va_arg(args, unsigned int));
	else if (format == 'x')
		count += ft_printhex_lower(va_arg(args, unsigned int));
	else if (format == 'X')
		count += ft_printhex_upper(va_arg(args, unsigned int));
	else if (format == '%')
		count += ft_printchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_find_arg(args, str[i]);
		}
		else
		{
			count += ft_printchar(str[i]);
		}
			i++;
	}
	va_end(args);
	return (count);
}

/*
int	main(void)
{
	char			c;
	char			*str;
	char			*str2;
	char			*str3;
	char			*str4;
	void			*ptr;
	int				n;
	int				n1;
	unsigned int	x;
	unsigned int	x1;
	unsigned int	hexl;
	unsigned int	hexu;

	c = 'G';
	str = "Hello, World!";
	str2 = "Ol@ Mund0!";
	str3 = " ";
	str4 = NULL;
	ptr = NULL;
	n = 0;
	n1 = -2147483648;
	x = 12342;
	x1 = 0;
	hexl = 12345678;
	hexu = 12345678;
	ft_printf("o char é: %c\n", c);
	ft_printf("a string é: %s\n", str);
	ft_printf("a string é: %s\n", str2);
	ft_printf("a string é: %s\n", str3);
	ft_printf("a string é: %s\n", str4);
	ft_printf("o endereço do ponteiro é: %p\n", ptr);
	ft_printf("o número é: %d\n", n);
	ft_printf("o número é: %d\n", n1);
	ft_printf("o número unsigned é: %u\n", x);
	ft_printf("o número unsigned é: %u\n", x1);
	ft_printf("o número em hexadecimal minúsculo é: %x\n", hexl);
	ft_printf("o número em hexadecimal maiúsculo é: %X\n", hexu);
	ft_printf("Percent: %%\n");
	return (0);
}
*/