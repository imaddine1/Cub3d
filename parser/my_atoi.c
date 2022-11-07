/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 08:50:04 by iharile           #+#    #+#             */
/*   Updated: 2022/10/06 16:03:44 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	my_atoi(char *str)
{
	int	i;
	int	res;

	if (!str)
		return (-1);
	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + str[i] - 48;
			if (res > 255)
				return (-1);
		}
		else
			return (-1);
		i++;
	}
	return (res);
}
