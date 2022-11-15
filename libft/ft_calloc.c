/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:53:51 by iharile           #+#    #+#             */
/*   Updated: 2021/11/20 14:27:44 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	p = malloc(count * size);
	i = 0;
	if (p == NULL)
		return (0);
	while (i < (count * size))
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
