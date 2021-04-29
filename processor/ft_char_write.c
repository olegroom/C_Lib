/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 20:03:04 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/29 17:01:00 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../base/ft_printf.h"

void	ft_char_w(t_parser *pos_proc, va_list *pa, int *length)
{
	char	ch;

	ch = va_arg(*pa, int);
	if (pos_proc->width < 1)
		*length = ft_putchar(ch);
	else
	{
		*length = pos_proc->width;
		if (pos_proc->flag == '-')
		{
			ft_putchar(ch);
			ft_fill_char(' ', pos_proc->width - 1);
		}
		else
		{
			ft_fill_char(' ', pos_proc->width - 1);
			ft_putchar(ch);
		}
	}
}
