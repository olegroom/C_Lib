/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:32:14 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/29 17:01:51 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../base/ft_printf.h"

int	fill_and_putnbr(int *num, t_parser *pos_proc)
{
	if (*num < 0)
	{
		if (pos_proc->flag == '0')
		{
			ft_putchar('-');
			*num *= -1;
		}
		if (pos_proc->flag == '0')
			ft_fill_char('0', pos_proc->width - ft_intlen(*num) - 1);
		else if (pos_proc->flag == '1')
			ft_fill_char(' ', pos_proc->width - ft_intlen(*num) - 1);
	}
	else
	{
		if (pos_proc->flag == '0')
			ft_fill_char('0', pos_proc->width - ft_intlen(*num));
		else if (pos_proc->flag == '1')
			ft_fill_char(' ', pos_proc->width - ft_intlen(*num));
	}
	ft_putnbr(*num);
	return (pos_proc->width);
}

int	putnbr_and_fill(int *num, t_parser *pos_proc)
{
	int	i;

	i = ft_intlen(*num);
	if (*num < 0)
	{
		ft_putnbr(*num);
		ft_fill_char(' ', pos_proc->width - i - 1);
	}
	else
	{
		ft_putnbr(*num);
		ft_fill_char(' ', pos_proc->width - i);
	}
	return (pos_proc->width);
}

int	precision_fill_and_putnbr(int *num, t_parser *pos_proc)
{
	if (*num < 0)
	{
		ft_fill_char(' ', pos_proc->width - pos_proc->precision - 1);
		ft_putchar('-');
		*num *= -1;
		ft_fill_char('0', pos_proc->precision - ft_intlen(*num));
		ft_putnbr(*num);
	}
	else if (pos_proc->flag == '1')
	{
		ft_fill_char(' ', pos_proc->width - pos_proc->precision);
		ft_fill_char('0', pos_proc->precision - ft_intlen(*num));
		ft_putnbr(*num);
	}
	return (pos_proc->width);
}

int	precision_putnbr_and_fill(int *num, t_parser *pos_proc)
{
	if (*num < 0)
	{
		ft_putchar('-');
		*num *= -1;
		ft_fill_char('0', pos_proc->precision - ft_intlen(*num));
		ft_putnbr(*num);
		ft_fill_char(' ', pos_proc->width - pos_proc->precision - 1);
	}
	else
	{
		ft_fill_char('0', pos_proc->precision - ft_intlen(*num));
		ft_putnbr(*num);
		ft_fill_char(' ', pos_proc->width - pos_proc->precision);
	}
	return (pos_proc->width);
}

void	ft_int_w(t_parser *pos_proc, va_list *pa, int *length)
{
	int	num;

	num = va_arg(*pa, int);
	if (pos_proc->precision != -1 && pos_proc->flag != '-')
		pos_proc->flag = '1';
	if (pos_proc->precision == 0 && num == 0 && pos_proc->width == 0)
		ft_putstr("");
	else if (pos_proc->precision == 0 && num == 0 && pos_proc->width > 0)
		*length = ft_fill_char(' ', pos_proc->width);
	else if (pos_proc->width <= ft_intlen(num) && \
pos_proc->precision <= ft_intlen(num))
		*length = ft_putnbr(num);
	else if (pos_proc->width >= ft_intlen(num)
		&& pos_proc->precision <= ft_intlen(num))
	{
		if (pos_proc->flag == '0' || pos_proc->flag == '1')
			*length = fill_and_putnbr(&num, pos_proc);
		else if (pos_proc->flag == '-')
			*length = putnbr_and_fill(&num, pos_proc);
	}
	else if (pos_proc->width <= pos_proc->precision
		&& pos_proc->precision >= ft_intlen(num))
		*length = ft_only_prec(&num, pos_proc);
	else
		*length = ft_wid_great_pres(&num, pos_proc);
}
