/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:52:42 by iharile           #+#    #+#             */
/*   Updated: 2022/10/17 12:05:39 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	add_point(char *s)
{
	*s = '.';
	return (0);
}

int	free_and_return(char **s, int ret)
{
	ft_free(s);
	return (ret);
}

int	dfs_recursion(char **split, int i, int j, char c)
{
	if (split[i][j] == ' ')
		return (0);
	if (split[i][j] == '0' || split[i][j] == c)
	{
		split[i][j] = '.';
		if (!dfs_recursion(split, i, j + 1, c))
			return (add_point(&split[i][j]));
		if (!dfs_recursion(split, i + 1, j, c))
			return (add_point(&split[i][j]));
		if (!dfs_recursion(split, i, j - 1, c))
			return (add_point(&split[i][j]));
		if (!dfs_recursion(split, i - 1, j, c))
			return (add_point(&split[i][j]));
	}
	return (1);
}

int	dfs(char *s, char c)
{
	char	**split;
	int		i;
	int		j;

	i = -1;
	split = ft_split(s, '\n');
	while (split[++i])
	{
		j = -1;
		while (split[i][++j])
		{
			if (split[i][j] == c)
			{
				if (!dfs_recursion(split, i, j, c))
					return (free_and_return(split, 0));
				else
					return (free_and_return(split, 1));
			}
		}
	}
	ft_free(split);
	return (1);
}
