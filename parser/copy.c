/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:57:42 by iharile           #+#    #+#             */
/*   Updated: 2022/11/09 16:32:39 by iharile          ###   ########.fr       */
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
	char	*trim;
	int		i;

	i = 0;
	trim = ft_strtrim(s, " ");
	size = count_until_space(trim);
	if (size == 0)
	{
		free (trim);
		return (0);
	}
	copy = malloc(sizeof(char) * (size + 1));
	if (!copy)
		return (NULL);
	while (i < size)
	{
		copy[i] = trim[i];
		i++;
	}
	copy[i] = 0;
	free (trim);
	return (copy);
}

char	*copy_after_space(char *s, char *bf)
{
	int		start;
	char	*trim;
	char	*trim2;

	if (!bf)
		return (0);
	trim = ft_strtrim(s, " ");
	start = count_until_space(trim);
	if (start == (int)ft_strlen(trim))
		return (0);
	trim2 = ft_strtrim(&trim[start + 1], " ");
	free (trim);
	if (ft_strlen(trim2) == 0)
	{
		free (trim2);
		return (NULL);
	}
	return (trim2);
}

int	check_before_after(char *bf, char *af)
{
	if (!bf && !af)
		return (1);
	if (bf && !af)
	{
		free (bf);
		return (0);
	}
	return (2);
}
