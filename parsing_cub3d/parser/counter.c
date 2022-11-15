/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:52:59 by iharile           #+#    #+#             */
/*   Updated: 2022/10/06 12:24:01 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	ft_splen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

long	sizeof_file(char *s)
{
	long	i;
	long	count;
	char	c[2];
	int		fd;

	i = 1;
	fd = open (s, O_RDONLY);
	count = 0;
	while (i)
	{
		i = read(fd, &c[0], 1);
		if (!i)
			break ;
		if (c[0] == '\t')
			msg_exit("\033[0;31m we are not requiered to handle tabs\033[0m");
		c[1] = 0;
		count++;
	}
	close (fd);
	return (count);
}
