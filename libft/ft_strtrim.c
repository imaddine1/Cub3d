/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:33:15 by iharile           #+#    #+#             */
/*   Updated: 2021/11/17 20:40:31 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char *s, char *set)
{
	int	i;
	int	j;
	int	d;

	i = 0;
	while (s[i])
	{
		j = 0;
		d = 0;
		while (set[j])
		{
			if (s[i] == set[j])
				d++;
			j++;
		}
		if (d == 0)
			break ;
		i++;
	}
	return (i);
}

static int	ft_end(char *s, char *set)
{
	int	i;
	int	j;
	int	d;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		j = 0;
		d = 0;
		while (set[j])
		{
			if (s[i] == set[j])
				d++;
			j++;
		}
		if (d == 0)
			break ;
		i--;
	}
	if (i == -1)
		i = (int)ft_strlen(s);
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*s;
	char	*p;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	s = (char *)s1;
	start = ft_start(s, (char *) set);
	end = ft_end(s, (char *) set);
	p = malloc(((end - start) + 2) * sizeof(char));
	if (p == NULL)
		return (0);
	i = 0;
	while (start <= end)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}
