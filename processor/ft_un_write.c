/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 20:41:29 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/29 17:04:52 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../base/ft_printf.h"

int	fill_and_putnbr_un(unsigned int *num, t_parser *pos_proc)
{
	if (pos_proc->flag == '0')
		ft_fill_char('0', pos_proc->width - ft_un_intlen(*num));
	else if (pos_proc->flag == '1')
		ft_fill_char(' ', pos_proc->width - ft_un_intlen(*num));
	ft_putnbr_uns_int(*num);
	return (pos_proc->width);
}

int	putnbr_and_fill_un(unsigned int *num, t_parser *pos_proc)
{
	int	i;

	i = ft_un_intlen(*num);
	ft_putnbr_uns_int(*num);
	ft_fill_char(' ', pos_proc->width - i);
	return (pos_proc->width);
}

int	precision_fill_and_putnbr_un(unsigned int *num, t_parser *pos_proc)
{
	ft_fill_char(' ', pos_proc->width - pos_proc->precision);
	ft_fill_char('0', pos_proc->precision - ft_un_intlen(*num));
	ft_putnbr_uns_int(*num);
	return (pos_proc->width);
}

int	precision_putnbr_and_fill_un(unsigned int *num, t_parser *pos_proc)
{
	ft_fill_char('0', pos_proc->precision - ft_un_intlen(*num));
	ft_putnbr_uns_int(*num);
	ft_fill_char(' ', pos_proc->width - pos_proc->precision);
	return (pos_proc->width);
}

void	ft_un_w(t_parser *pos_proc, va_list *pa, int *length)
{
	unsigned int	num;

	num = va_arg(*pa, unsigned int);
	if (pos_proc->precision != -1 && pos_proc->flag != '-')
		pos_proc->flag = '1';
	if (pos_proc->precision == 0 && num == 0 && pos_proc->width >= 0)
		*length = ft_fill_char(' ', pos_proc->width);
	else if (pos_proc->width <= ft_un_intlen(num) && \
pos_proc->precision <= ft_un_intlen(num))
		*length = ft_putnbr_uns_int(num);
	else if (pos_proc->width >= ft_un_intlen(num) && \
pos_proc->precision <= ft_un_intlen(num))
		*length = sokrashenie_un_write(&num, pos_proc);
	else if (pos_proc->width <= pos_proc->precision && \
pos_proc->precision >= ft_un_intlen(num))
		*length = ft_only_prec_un(&num, pos_proc);
	else
	{
		if (pos_proc->flag == '0' || pos_proc->flag == '1')
			*length = precision_fill_and_putnbr_un(&num, pos_proc);
		else if (pos_proc->flag == '-')
			*length = precision_putnbr_and_fill_un(&num, pos_proc);
	}
}
