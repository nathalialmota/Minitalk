/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nade-lim <nade-lim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:31:48 by nade-lim          #+#    #+#             */
/*   Updated: 2025/01/14 18:41:51 by nade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_is_waiting_for_response = 0;

void	update_wait_response(int signal)
{
	(void)signal;
	g_is_waiting_for_response = 1;
}

void	send_string_in_bits(int pid, char *str)
{
	static int	bit;

	while (*str != '\0')
	{
		bit = 8;
		while (bit--)
		{
			g_is_waiting_for_response = 0;
			if ((*str >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			while (g_is_waiting_for_response == 0)
				;
		}
		str++;
	}
	bit = 8;
	while (bit--)
	{
		g_is_waiting_for_response = 0;
		kill(pid, SIGUSR1);
		while (g_is_waiting_for_response == 0)
			;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Usage: %s [PID] [STRING]\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID\n");
		return (1);
	}
	signal(SIGUSR1, update_wait_response);
	signal(SIGUSR2, update_wait_response);
	send_string_in_bits(pid, argv[2]);
	return (0);
}
