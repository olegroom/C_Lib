/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:59:55 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/29 16:49:47 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../base/ft_printf.h"

void	ft_type_pars(char ****ps, t_parser *pos_proc)
{
	if (ft_strchr(SPEC, ****ps))
		pos_proc->type = ****ps;
	else
		(***ps)++;
	(***ps)++;
}
