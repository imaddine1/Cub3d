/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:09:12 by iharile           #+#    #+#             */
/*   Updated: 2021/11/22 12:04:02 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		j;
	char	*p;

	if (!s || !f)
		return (0);
	i = ft_strlen((char *)s);
	p = malloc ((i + 1) * (sizeof(char)));
	if (!p)
		return (0);
	j = 0;
	while (j < i)
	{
		p[j] = f(j, s[j]);
		j++;
	}
	p[j] = '\0';
	return (p);
}
