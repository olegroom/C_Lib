/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:46:23 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/29 16:54:56 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	reduce_for_width(char *str, t_parser *pos_proc)
{
	if (pos_proc->flag == '0' || pos_proc->flag == '1')
		fill_and_putnbr_x(str, pos_proc);
	else if (pos_proc->flag == '-')
		putnbr_and_fill_x(str, pos_proc);
	return (pos_proc->width);
}

int	reduce_for_precision(char *str, t_parser *pos_proc)
{
	if (pos_proc->flag == '0' || pos_proc->flag == '1')
		precision_fill_and_putnbr_x(str, pos_proc);
	else if (pos_proc->flag == '-')
		precision_putnbr_and_fill_x(str, pos_proc);
	return (pos_proc->width);
}

int	ft_putnbr_uns_int(unsigned int src)
{
	unsigned int	i;

	i = src;
	if (src >= 10)
	{
		ft_putnbr_uns_int(src / 10);
		ft_putchar((src % 10) + '0');
	}
	else
		ft_putchar(src + 48);
	return (ft_intlen_un_int(i));
}

int	ft_intlen_un_int(unsigned int i)
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

int	ft_wid_great_pres(int *num, t_parser *pos_proc)
{
	int	i;

	i = 0;
	if (pos_proc->flag == '-')
		i = precision_putnbr_and_fill(num, pos_proc);
	else
		i = precision_fill_and_putnbr(num, pos_proc);
	return (i);
}
