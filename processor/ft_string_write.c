/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:01:03 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/29 17:04:25 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../base/ft_printf.h"

int	ft_first_block(t_parser *pos_proc, char *str)
{
	{
		if (pos_proc->flag == '1')
		{
			ft_fill_char(' ', pos_proc->width - ft_strlen(str));
			ft_putstr(str);
		}
		else if (pos_proc->flag == '0')
		{
			ft_fill_char('0', pos_proc->width - ft_strlen(str));
			ft_putstr(str);
		}
		else if (pos_proc->flag == '-')
		{
			ft_putstr(str);
			ft_fill_char(' ', pos_proc->width - ft_strlen(str));
		}
	}
	return (pos_proc->width);
}

int	ft_second_block(t_parser *pos_proc, char *str)
{
	{
		if (pos_proc->flag == '1')
		{
			ft_fill_char(' ', pos_proc->width - pos_proc->precision);
			ft_putstr_n(str, pos_proc->precision);
		}
		else if (pos_proc->flag == '-')
		{
			ft_putstr_n(str, pos_proc->precision);
			ft_fill_char(' ', pos_proc->width - pos_proc->precision);
		}
	}
	return (pos_proc->width);
}

void	ft_string_w(t_parser *pos_proc, va_list *pa, int *length)
{
	char	*str;

	str = va_arg(*pa, char *);
	if (str == NULL)
		str = "(null)";
	if (pos_proc->precision == 0)
		*length = pos_proc->width;
	if ((pos_proc->precision >= ft_strlen(str) || \
pos_proc->precision == -1) && pos_proc->width <= ft_strlen(str))
		*length = ft_putstr(str);
	else if ((pos_proc->precision >= ft_strlen(str) || \
pos_proc->precision == -1) && (pos_proc->width >= ft_strlen(str)))
		*length = ft_first_block(pos_proc, str);
	else if ((pos_proc->precision <= ft_strlen(str) && \
pos_proc->precision != -1) && pos_proc->width > pos_proc->precision)
		*length = ft_second_block(pos_proc, str);
	else if (pos_proc->precision < ft_strlen(str) && \
pos_proc->width <= pos_proc->precision)
		*length = ft_putstr_n(str, pos_proc->precision);
}
