/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 21:43:30 by iharile           #+#    #+#             */
/*   Updated: 2021/11/14 22:07:19 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	i;
	long	nb;

	nb = n;
	if (nb < 0)
	{	
		i = '-';
		write (fd, &i, 1);
		nb *= (-1);
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	i = (nb % 10) + 48;
	write (fd, &i, 1);
}
