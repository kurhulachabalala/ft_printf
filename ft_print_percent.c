/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchabala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 13:27:53 by kchabala          #+#    #+#             */
/*   Updated: 2018/09/28 13:27:55 by kchabala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_percent(t_flist *lst, char c)
{
	int		len;

	len = 0;
	if ((lst->flags)[2] == '0')
		(lst->flags)[0] = '0';
	if ((lst->flags)[3] != '-' && lst->width > 1)
		while (((lst->width)-- - 1))
			len += ft_print_char((lst->flags)[0]);
	len += ft_print_char(c);
	if (lst->width > 1 && (lst->flags)[3] == '-')
		while ((lst->width)-- - 1)
			len += ft_print_char(' ');
	return (len);
}
