/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:51:36 by jugingas          #+#    #+#             */
/*   Updated: 2022/11/25 11:30:11 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_size(int n)
{
	int				size;
	unsigned int	pow;

	size = 1;
	if (n >= 1000000000)
		return (10);
	if (n < 0)
	{
		size++;
		n = -n;
	}
	pow = 10;
	while (pow <= (unsigned int)n)
	{
		size++;
		pow *= 10;
	}
	return (size);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	i;

	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	i = get_size(n);
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
	return (i);
}
