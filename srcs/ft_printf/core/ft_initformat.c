/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initformat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:08:58 by obelair           #+#    #+#             */
/*   Updated: 2021/01/08 10:59:12 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "incs/ft_printf.h"

void	ft_initformat(va_list *ap, t_format *tf, int fd)
{
	tf->ap = ap;
	tf->minus = FALSE;
	tf->zero = FALSE;
	tf->hash = FALSE;
	tf->space = FALSE;
	tf->plus = FALSE;
	tf->point = FALSE;
	tf->spec = 0;
	tf->wprec = 0;
	tf->width = 0;
	tf->length = 0;
	tf->base = 0;
	tf->fd = fd;
}
