/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:59:53 by jugingas          #+#    #+#             */
/*   Updated: 2022/11/25 11:29:53 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_len(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

void	print_ptr(uintptr_t	ptr)
{
	if (ptr >= 16)
	{
		print_ptr(ptr / 16);
		print_ptr(ptr % 16);
	}
	else if (ptr <= 9)
		ft_putchar_fd(ptr + '0', 1);
	else
		ft_putchar_fd(ptr + 'a' - 10, 1);
}

int	flag_p(uintptr_t ptr)
{
	int	len;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		len = 2;
		write(1, "0x", 2);
		print_ptr(ptr);
		len += get_len(ptr);
	}
	return (len);
}
