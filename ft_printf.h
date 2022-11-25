/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:19:27 by jugingas          #+#    #+#             */
/*   Updated: 2022/11/25 11:32:03 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <unistd.h>
# include <strings.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int nb, int fd);
int		ft_printf(const char *str, ...);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		flag_p(uintptr_t ptr);

#endif
