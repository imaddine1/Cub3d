/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 07:51:40 by iharile           #+#    #+#             */
/*   Updated: 2021/11/18 17:51:30 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	j;

	j = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		len = 0;
	else if (ft_strlen(s) < len)
		len = ft_strlen(s) - start;
	s2 = malloc ((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (0);
	while (s[start] && j < len)
		s2[j++] = s[start++];
	s2[j] = '\0';
	return (s2);
}
