/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 20:03:40 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/29 16:54:05 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fill_char(char ch, int i)
{
	int	j;

	j = 0;
	while (i--)
	{
		ft_putchar(ch);
		j++;
	}
	return (j);
}

int	ft_only_prec(int *num, t_parser *pos_proc)
{
	if (*num < 0)
	{
		ft_putchar('-');
		*num *= -1;
		ft_fill_char('0', pos_proc->precision - ft_intlen(*num));
		ft_putnbr(*num);
		return (pos_proc->precision + 1);
	}
	else
	{
		ft_fill_char('0', pos_proc->precision - ft_intlen(*num));
		ft_putnbr(*num);
		return (pos_proc->precision);
	}
	return (0);
}

int	ft_only_prec_x(char *str, t_parser *pos_proc)
{
	ft_fill_char('0', pos_proc->precision - ft_strlen(str));
	ft_putstr(str);
	return (pos_proc->precision);
}

int	ft_only_prec_un(unsigned int *num, t_parser *pos_proc)
{
	ft_fill_char('0', pos_proc->precision - ft_un_intlen(*num));
	ft_putnbr(*num);
	return (pos_proc->precision);
}

int	ft_putstr_n(const char *s, int n)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (n--)
		write(1, &s[i++], sizeof(char));
	return (i);
}
