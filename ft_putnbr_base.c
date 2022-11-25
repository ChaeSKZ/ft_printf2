/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:46:07 by jugingas          #+#    #+#             */
/*   Updated: 2022/11/25 11:30:03 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base || ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j]
				|| base[i] == '-' || base[i] == '+')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	print(unsigned int nbr, char *base, unsigned int base_len, int size)
{
	if (nbr > base_len - 1)
	{
		size = print(nbr / base_len, base, base_len, size);
		nbr %= base_len;
	}
	write(1, &base[nbr], 1);
	return (size + 1);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int	size;

	size = 0;
	if (!check_base(base))
		return (-1);
	size = print(nbr, base, ft_strlen(base), size);
	return (size);
}
