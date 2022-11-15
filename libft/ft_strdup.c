/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:05:27 by iharile           #+#    #+#             */
/*   Updated: 2021/11/19 16:38:51 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	char	*p;
	int		i;

	s = (char *)s1;
	i = 0;
	while (s[i])
		i++;
	p = malloc((i + 1) * sizeof(char));
	if (p == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
