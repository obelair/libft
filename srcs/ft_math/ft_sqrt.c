/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 10:54:12 by obelair           #+#    #+#             */
/*   Updated: 2021/08/06 15:57:23 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_sqrt(int	nb)
{
	int		i;
	float	sqrt;

	sqrt = 0;
	i = 1;
	while (nb >= i)
	{
		nb -= i;
		sqrt++;
		i += 2;
	}
	return (sqrt);
}
