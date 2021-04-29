/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_write.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:00:10 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/29 17:02:53 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../base/ft_printf.h"

char	*dec_to_hex_point(unsigned long num)
{
	int		temp;
	char	hex[100];
	char	*str;
	int		i;

	i = 0;
	temp = 0;
	if (num == 0)
		return (ft_strdup("0"));
	while (num != 0)
	{
		temp = num % 16;
		hex[i] = HEX_SM[temp];
		i++;
		num /= 16;
	}
	hex[i] = '\0';
	str = ft_strdup(hex);
	return (str);
}

void	help_to_pointer(char *str)
{
	ft_putstr("0x");
	ft_putstr(str);
}

int	work_with_null(t_parser *pos_proc, char *str)
{
	int	i;

	i = 0;
	if (pos_proc->precision == 0)
		str = ft_strdup("0x");
	else
		str = ft_strdup("0x0");
	if (pos_proc->width <= ft_strlen(str))
		i = ft_putstr(str);
	else if (pos_proc->width >= ft_strlen(str))
	{
		if (pos_proc->flag == '-')
		{
			ft_putstr(str);
			ft_fill_char(' ', pos_proc->width - ft_strlen(str));
		}
		else if (pos_proc->flag == '1' || pos_proc->flag == '0')
		{
			ft_fill_char(' ', pos_proc->width - ft_strlen(str));
			ft_putstr(str);
		}
		i = pos_proc->width;
	}
	free(str);
	return (i);
}

void	ft_width_pointer(t_parser *pos_proc, char *str)
{
	if (pos_proc->flag == '-')
	{
		help_to_pointer(str);
		ft_fill_char(' ', pos_proc->width - ft_strlen(str) - 2);
	}
	else
	{
		ft_fill_char(' ', pos_proc->width - ft_strlen(str) - 2);
		help_to_pointer(str);
	}
}

void	ft_pointer_w(t_parser *pos_proc, va_list *pa, int *length)
{
	unsigned long	num;
	char			*str;

	str = NULL;
	num = va_arg(*pa, long);
	if (num == 0)
	{
		*length = work_with_null(pos_proc, str);
		return ;
	}
	else
		str = revers_str(dec_to_hex_point(num));
	if (pos_proc->width <= ft_strlen(str) + 2)
	{
		help_to_pointer(str);
		*length = ft_strlen(str) + 2;
	}
	else if (pos_proc->width >= ft_strlen(str) + 2)
	{
		*length = pos_proc->width;
		ft_width_pointer(pos_proc, str);
	}
	free(str);
}
