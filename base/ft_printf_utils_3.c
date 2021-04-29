/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 00:43:09 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/29 16:54:28 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*revers_str(char *src)
{
	int		i;
	int		j;
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	i = 0;
	j = ft_strlen(src) - 1;
	while (i < ft_strlen(src))
	{
		dest[i] = src[j];
		i++;
		j--;
	}
	dest[i] = '\0';
	free(src);
	src = NULL;
	return (dest);
}

char	*dec_to_hex_b(unsigned int num)
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
		hex[i] = HEX_B[temp];
		i++;
		num /= 16;
	}
	hex[i] = '\0';
	str = ft_strdup(hex);
	return (str);
}

char	*dec_to_hex_sm(unsigned int num)
{
	int		temp;
	char	hex[100];
	char	*str;
	int		i;

	if (num == 0)
		return (ft_strdup("0"));
	i = 0;
	temp = 0;
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

char	*depend_on_case(unsigned int *num, t_parser *pos_proc)
{
	char	*str;

	str = NULL;
	if (pos_proc->type == 'x')
		str = revers_str(dec_to_hex_sm(*num));
	else
		str = revers_str(dec_to_hex_b(*num));
	return (str);
}

int	sokrashenie_un_write(unsigned int *num, t_parser *pos_proc)
{
	int	i;

	i = 0;
	if (pos_proc->flag == '0' || pos_proc->flag == '1')
		i = fill_and_putnbr_un(num, pos_proc);
	else if (pos_proc->flag == '-')
		i = putnbr_and_fill_un(num, pos_proc);
	return (i);
}
