/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 22:43:15 by iharile           #+#    #+#             */
/*   Updated: 2022/10/06 16:00:48 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	msg_exit(char *str)
{
	printf("%s\n", str);
	exit(1);
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
