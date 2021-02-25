/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:06:43 by obelair           #+#    #+#             */
/*   Updated: 2021/02/25 13:28:18 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_str.h"
#include "../../incs/ft_mem.h"

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*cat;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	i = -1;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(cat = ft_calloc(lens1 + lens2 + 1, sizeof(char))))
		return (NULL);
	while (s1 && s1[++i])
		cat[i] = s1[i];
	j = 0;
	while (s2 && s2[j])
	{
		cat[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (cat);
}
