/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:36:00 by iharile           #+#    #+#             */
/*   Updated: 2022/11/10 11:05:25 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	check_extension(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = ft_strrchr(str, '.');
	if (ft_strncmp(new_str, ".cub", ft_strlen(new_str)))
	{
		msg_exit("the extension of the file must be .cub");
	}
}
