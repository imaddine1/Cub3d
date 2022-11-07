/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:57:42 by iharile           #+#    #+#             */
/*   Updated: 2022/11/01 20:07:21 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	count_until_space(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			break ;
		i++;
	}
	return (i);
}

char	*copy_before_space(char *s)
{
	char	*copy;
	int		size;
	int		i;

	i = 0;
	size = count_until_space(s);
	copy = malloc(sizeof(char) * (size + 1));
	if (!copy || (int)ft_strlen(s) == size)
		return (NULL);
	while (i < size)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

char	*copy_after_space(char *s)
{
	int		start;
	char	*trim;

	start = count_until_space(s);
	trim = ft_strtrim(&s[start + 1], " ");
	return (trim);
}
