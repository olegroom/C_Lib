/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sm_and_big_x_write.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 04:28:26 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/29 17:03:45 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../base/ft_printf.h"

void	fill_and_putnbr_x(char *str, t_parser *pos_proc)
{
	if (pos_proc->flag == '0')
		ft_fill_char('0', pos_proc->width - ft_strlen(str));
	else if (pos_proc->flag == '1')
		ft_fill_char(' ', pos_proc->width - ft_strlen(str));
	ft_putstr(str);
}

void	putnbr_and_fill_x(char *str, t_parser *pos_proc)
{
	int	i;

	i = ft_strlen(str);
	ft_putstr(str);
	ft_fill_char(' ', pos_proc->width - i);
}

void	precision_fill_and_putnbr_x(char *str, t_parser *pos_proc)
{
	if (pos_proc->flag == '0')
	{
		ft_fill_char('0', pos_proc->width - pos_proc->precision);
		ft_fill_char('0', pos_proc->precision - ft_strlen(str));
		ft_putstr(str);
	}
	else if (pos_proc->flag == '1')
	{
		ft_fill_char(' ', pos_proc->width - pos_proc->precision);
		ft_fill_char('0', pos_proc->precision - ft_strlen(str));
		ft_putstr(str);
	}
}

void	precision_putnbr_and_fill_x(char *str, t_parser *pos_proc)
{
	ft_fill_char('0', pos_proc->precision - ft_strlen(str));
	ft_putstr(str);
	ft_fill_char(' ', pos_proc->width - pos_proc->precision);
}

void	ft_sm_and_big_x_w(t_parser *pos_proc, va_list *pa, int *length)
{
	unsigned int	num;
	char			*str;

	num = va_arg(*pa, long);
	str = depend_on_case(&num, pos_proc);
	if (pos_proc->precision != -1 && pos_proc->flag != '-')
		pos_proc->flag = '1';
	if (pos_proc->precision == 0 && num == 0)
		*length = ft_fill_char(' ', pos_proc->width);
	else if (pos_proc->width <= ft_strlen(str)
		&& pos_proc->precision <= ft_strlen(str))
		*length = ft_putstr(str);
	else if (pos_proc->width >= ft_strlen(str)
		&& pos_proc->precision <= ft_strlen(str))
		*length = reduce_for_width(str, pos_proc);
	else if ((pos_proc->width <= pos_proc->precision)
		&& (pos_proc->precision >= ft_strlen(str)))
		*length = ft_only_prec_x(str, pos_proc);
	else
		*length = reduce_for_precision(str, pos_proc);
	free(str);
}
