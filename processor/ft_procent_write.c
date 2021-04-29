/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_procent_write.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 20:24:47 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/29 16:49:09 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../base/ft_printf.h"

void	ft_procent_w(t_parser *pos_proc, int *length)
{
	if (pos_proc->width >= 1)
		*length = pos_proc->width;
	else
		*length = 1;
	if (pos_proc->width >= 1 && pos_proc->flag == '-')
	{
		ft_putchar('%');
		ft_fill_char(' ', pos_proc->width - 1);
	}
	else if (pos_proc->width > 1 && (pos_proc->flag == '0' ||\
pos_proc->flag == '1'))
	{
		if (pos_proc->flag == '0')
		{
			ft_fill_char('0', pos_proc->width - 1);
			ft_putchar('%');
		}
		else if (pos_proc->flag == '1')
		{
			ft_fill_char(' ', pos_proc->width - 1);
			ft_putchar('%');
		}
	}
	else
		ft_putchar('%');
}
