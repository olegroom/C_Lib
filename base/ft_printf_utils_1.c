/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:58:04 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/29 16:55:43 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, sizeof(char));
	return (1);
}

int	ft_putstr(const char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], sizeof(char));
		i++;
	}
	return (i);
}

int	ft_putnbr(long src)
{
	long	i;

	i = src;
	if (src < 0)
	{
		ft_putchar('-');
		src = -src;
	}
	if (src >= 10)
	{
		ft_putnbr(src / 10);
		ft_putchar((src % 10) + '0');
	}
	else
		ft_putchar(src + 48);
	if (i < 0)
		return (ft_intlen(i) + 1);
	else
		return (ft_intlen(i));
}

int	ft_intlen(int i)
{
	int	j;

	j = 0;
	if (i == 0)
		return (1);
	if (i < 0)
		i *= -1;
	while (i)
	{
		i /= 10;
		j++;
	}
	return (j);
}

int	ft_un_intlen(unsigned int i)
{
	int	j;

	j = 0;
	if (i == 0)
		return (1);
	if (i < 0)
		i *= -1;
	while (i)
	{
		i /= 10;
		j++;
	}
	return (j);
}
