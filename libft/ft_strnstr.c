/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:29:23 by iharile           #+#    #+#             */
/*   Updated: 2021/11/22 11:22:53 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystak, const char *needle, size_t len)
{
	char	*n;
	char	*h;
	size_t	i;
	size_t	j;

	n = (char *)needle;
	h = (char *)haystak;
	i = 0;
	if (*n == '\0')
		return (h);
	while (h[i] && i < len)
	{
		j = 0;
		while (n[j] && h[i + j])
		{
			if (h[i + j] == n[j] && i + j < len)
				j++;
			else
				break ;
		}
		if (n[j] == '\0')
			return (h + i);
		i++;
	}
	return (0);
}
