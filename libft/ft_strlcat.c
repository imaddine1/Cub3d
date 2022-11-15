/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:43:37 by iharile           #+#    #+#             */
/*   Updated: 2021/11/20 13:22:31 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l_dst;
	size_t	l_src;

	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	i = 0;
	if (dstsize <= l_dst)
		return (l_src + dstsize);
	while (src[i] && l_dst + i < dstsize - 1)
	{
		dst[l_dst + i] = src[i];
		i++;
	}
	dst[l_dst + i] = '\0';
	return (l_src + l_dst);
}
