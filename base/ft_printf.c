/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:58:30 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/29 16:52:49 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parser_init(t_parser *pos)
{
	pos->width = 0;
	pos->type = '0';
	pos->precision = -1;
	pos->flag = '1';
}

void	fill_struct(char ***ps, t_parser *pos_proc, va_list *pa)
{
	ft_flag_pars(&ps, pos_proc);
	ft_width_pars(&ps, pos_proc, pa);
	ft_precision_pars(&ps, pos_proc, pa);
	ft_type_pars(&ps, pos_proc);
}

int	ft_parser(char **ps, va_list *pa)
{
	t_parser	pos_proc;
	int			length;

	length = 0;
	(*ps)++;
	parser_init(&pos_proc);
	fill_struct(&ps, &pos_proc, pa);
	if (pos_proc.type == 'd' || pos_proc.type == 'i')
		ft_int_w(&pos_proc, pa, &length);
	else if (pos_proc.type == 'c')
		ft_char_w(&pos_proc, pa, &length);
	else if (pos_proc.type == 's')
		ft_string_w(&pos_proc, pa, &length);
	else if (pos_proc.type == '%')
		ft_procent_w(&pos_proc, &length);
	else if (pos_proc.type == 'p')
		ft_pointer_w(&pos_proc, pa, &length);
	else if (pos_proc.type == 'u')
		ft_un_w(&pos_proc, pa, &length);
	else if (pos_proc.type == 'X' || pos_proc.type == 'x')
		ft_sm_and_big_x_w(&pos_proc, pa, &length);
	else
		return (0);
	return (length);
}

int	defense_from(char *ps)
{
	char	*temp;

	temp = ps;
	while (*temp++)
	{
		if (*temp == '\0')
			return (1);
		else if (ft_strchr(SPEC, *temp))
			break ;
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	char	*ps;
	int		length;
	va_list	pa;

	ps = (char *)s;
	length = 0;
	va_start(pa, s);
	while (*ps)
	{
		if (*ps == '%')
		{
			if (defense_from(ps))
				return (0);
			length += ft_parser(&ps, &pa);
		}
		else
			length += ft_putchar(*ps++);
	}
	va_end(pa);
	return (length);
}
