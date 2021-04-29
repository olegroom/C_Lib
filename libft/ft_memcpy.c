/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:13:52 by rosfryd           #+#    #+#             */
/*   Updated: 2021/04/29 13:55:18 by rosfryd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tmp1;
	const char	*tmp2;

	tmp1 = dest;
	tmp2 = src;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (n--)
		*tmp1++ = *tmp2++;
	return (dest);
}
