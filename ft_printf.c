/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:32:32 by jugingas          #+#    #+#             */
/*   Updated: 2022/11/25 15:46:23 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_size_unsigned(unsigned int n)
{
	int				size;
	unsigned int	pow;

	size = 1;
	pow = 10;
	if (n >= 1000000000)
		return (10);
	while (pow <= n)
	{
		size++;
		pow *= 10;
	}
	return (size);
}

int	ft_putnbr_fd_unsigned(unsigned int n, int fd)
{
	int	i;

	i = get_size_unsigned(n);
	if (n >= 10)
	{
		ft_putnbr_fd_unsigned(n / 10, fd);
		ft_putnbr_fd_unsigned(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
	return (i);
}

int	check(char c, va_list lst)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(lst, int), 1));
	if (c == 'i' || c == 'd')
		return (ft_putnbr_fd(va_arg(lst, int), 1));
	if (c == 's')
		return (ft_putstr_fd(va_arg(lst, char *), 1));
	if (c == 'p')
		return (flag_p(va_arg(lst, uintptr_t)));
	if (c == 'u')
		return (ft_putnbr_fd_unsigned(va_arg(lst, unsigned int), 1));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(lst, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_base(va_arg(lst, unsigned int), "0123456789ABCDEF"));
	return (ft_putchar_fd('%', 1));
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	lst;
	int		size;

	if (!str)
		return (-1);
	va_start(lst, str);
	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += check(str[i + 1], lst);
			i++;
		}
		else
			size += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(lst);
	return (size);
}
