/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:23:54 by iharile           #+#    #+#             */
/*   Updated: 2021/11/07 14:56:31 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;
	int		j;
	char	b;

	j = 0;
	i = 0;
	str = (char *)s;
	b = (char)c;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == b)
			return (&str[i]);
		i--;
	}
	return (0);
}
