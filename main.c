/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:25:13 by pthomas           #+#    #+#             */
/*   Updated: 2021/01/08 15:48:43 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>
#include "incs/ft_int.h"

//#include "get_next_line.h"

int		main(void)
{
	/* char	*line;
	int		fd1;
	int		fd2;
	int		ret1;
	int		ret2;
	line = 0;
	fd1 = 0;
	fd2 = 0;
	ret1 = 1;
	ret2 = 1;
	while (ret1 > 0 && ret2 > 0)
	{
		ret1 = get_next_line(fd1, &line);
		printf("return1 = %d | line = %s\n", ret1, line);
		free(line);
		ret2 = get_next_line(fd2, &line);
		printf("return2 = %d | line = %s\n", ret2, line);
		free(line);
	}
	close(fd1);
	close(fd2); *//* 
	printf("|%d|\n", atoi("9223372036854775810"));
	printf("|%d|\n", ft_atoi("9223372036854775810"));
	ft_printf("|%d|\n", atoi("92233720368547758010"));
	ft_printf("|%d|\n", ft_atoi("9223372036854775810")); */
	printf("|%s|\n", ft_itoa(INT_MAX));
	printf("|%s|\n", ft_itoa(INT_MIN));
	printf("|%s|\n", ft_itoa(0));
	printf("|%s|\n", ft_itoa(000000000));
	return (0);
}
