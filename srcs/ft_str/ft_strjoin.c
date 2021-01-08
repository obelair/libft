/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:06:43 by obelair           #+#    #+#             */
/*   Updated: 2021/01/08 10:59:12 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "incs/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*cat;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	if (!(cat = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cat[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		cat[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	cat[ft_strlen(s1) + i] = 0;
	return (cat);
}
