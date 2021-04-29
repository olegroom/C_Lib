/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:59:33 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/29 16:49:50 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../base/ft_printf.h"

void	ft_width_pars(char ****ps, t_parser *pos_proc, va_list *pa)
{
	int		num;

	num = 0;
	if (****ps == '\0')
		return ;
	if (****ps == '*')
	{
		pos_proc->width = va_arg(*pa, int);
		if (pos_proc->width < 0)
		{
			pos_proc->width *= -1;
			pos_proc->flag = '-';
		}
		(***ps)++;
	}
	else if (****ps != '.' && ft_strchr(SPEC, ****ps) == 0)
	{
		pos_proc->width = ft_atoi(***ps);
		if (pos_proc->width < 0)
			pos_proc->width *= -1;
		num = ft_intlen(pos_proc->width);
		***ps += num;
	}
}
