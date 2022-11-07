/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 22:43:15 by iharile           #+#    #+#             */
/*   Updated: 2022/11/07 19:20:08 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	msg_exit(char *str)
{
	printf("%s\n", str);
	system("leaks cub3D");
	exit(0);
}

void	free_and_msg(char **m1, char **m2, char *s1, char *msg)
{
	if (m1)
		ft_free (m1);
	if (m2)
		ft_free(m2);
	if (s1)
		free (s1);
	printf ("%s\n", msg);
	system("leaks cub3D");
	exit(0);
}

void	ft_free(char **s)
{
	int	i;

	i = -1;
	if (!s)
		return ;
	while (s[++i])
		free(s[i]);
	free (s);
}

int	free_return(char **db_str, char *str1, char *str2, int ret)
{
	ft_free(db_str);
	free (str1);
	free(str2);
	return (ret);
}
