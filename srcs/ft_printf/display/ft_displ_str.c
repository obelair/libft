/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displ_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:44:58 by obelair           #+#    #+#             */
/*   Updated: 2021/01/08 10:59:12 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "incs/ft_printf.h"

static void	ft_display(t_format *tf, char *str)
{
	int		i;

	i = 0;
	if (tf->point)
		while (i < ft_min(tf->length, tf->wprec))
			ft_putchar_fd(str[i++], tf->fd);
	else
		while (i < tf->length)
			ft_putchar_fd(str[i++], tf->fd);
	if (tf->point)
		tf->nbprint += ft_min(tf->length, tf->wprec);
	else
		tf->nbprint += tf->length;
}

void		ft_displ_str(t_format *tf)
{
	char	*str;

	if (!(str = va_arg(*(tf->ap), char *)))
		str = "(null)";
	tf->length = ft_strlen(str);
	if (tf->width && tf->point)
		tf->width -= ft_min(tf->length, tf->wprec);
	else if (tf->width)
		tf->width -= tf->length;
	if (tf->zero && !tf->minus)
		ft_displ_zero(tf, tf->width);
	else if (!tf->zero && !tf->minus)
		ft_displ_spc(tf, tf->width);
	ft_display(tf, str);
	if (tf->minus)
		ft_displ_spc(tf, tf->width);
}
