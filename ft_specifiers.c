/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchabala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 13:29:53 by kchabala          #+#    #+#             */
/*   Updated: 2018/09/28 13:32:56 by kchabala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_out(t_flist *lst, va_list va)
{
	int		res;

	res = 0;
	if (lst->spec == '%')
		res = (ft_print_percent(lst, '%'));
	else if (lst->spec == 'c' || lst->spec == 'C')
		res = (ft_handling_char(lst, va_arg(va, void *)));
	else if (lst->spec == 's' || lst->spec == 'S')
		res = (ft_handling_str(lst, va_arg(va, void *)));
	else if (lst->spec == 'd' || lst->spec == 'i' || lst->spec == 'D')
		res = (ft_handling_digit(lst, va_arg(va, void *)));
	else if (lst->spec == 'u' || lst->spec == 'U')
		res = (ft_handling_unsigned_digit(lst, va_arg(va, void *)));
	else if (lst->spec == 'x' || lst->spec == 'X')
		res = (ft_handling_x(lst, va_arg(va, void *)));
	else if (lst->spec == 'o' || lst->spec == 'O')
		res = (ft_handling_o(lst, va_arg(va, void *)));
	else if (lst->spec == 'p')
		res = (ft_handling_ptr(lst, va_arg(va, void *)));
	else
		res = (ft_handling_char(lst, va_arg(va, void *)));
	ft_strdel(&(lst->flags));
	return (res);
}
