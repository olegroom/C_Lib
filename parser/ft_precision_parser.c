/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:57:42 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/29 17:00:24 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../base/ft_printf.h"

void	ft_precision_pars(char ****ps, t_parser *pos_proc, va_list *pa)
{
	int	num;

	if (****ps == '.')
	{
		(***ps)++;
		if (****ps == '0')
			(***ps)++;
		if (****ps == '*')
		{
			pos_proc->precision = va_arg(*pa, int);
			if (pos_proc->precision < 0)
				pos_proc->precision = -1;
			(***ps)++;
		}
		else if (****ps < '0' || ****ps > '9')
			pos_proc->precision = 0;
		else
		{
			pos_proc->precision = ft_atoi(***ps);
			num = ft_intlen(pos_proc->precision);
			***ps = ***ps + num;
		}
	}
	else
		pos_proc->precision = -1;
}
