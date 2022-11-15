/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:41:24 by iharile           #+#    #+#             */
/*   Updated: 2021/11/19 16:37:14 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	int				i;
	char			b;

	i = 0;
	str = (char *)s;
	b = (char)c;
	while (str[i])
	{
		if (str[i] == b)
			return (&str[i]);
		i++;
	}
	if (str[i] == b)
		return (&str[i]);
	return (0);
}
