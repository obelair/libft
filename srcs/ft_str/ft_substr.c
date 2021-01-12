/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:55:46 by obelair           #+#    #+#             */
/*   Updated: 2021/01/11 09:45:09 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_str.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	lens;

	if (!s)
		return (NULL);
	if (len > (lens = ft_strlen(s)))
		len = lens - start;
	if (!(sub = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	if (lens > (size_t)start)
		while (i < len && s[start + i])
		{
			sub[i] = s[start + i];
			i++;
		}
	sub[i] = 0;
	return (sub);
}
