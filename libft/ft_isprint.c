/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:42:41 by iharile           #+#    #+#             */
/*   Updated: 2021/11/22 10:57:40 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	unsigned char	print;

	print = (unsigned char)c;
	if (print >= 32 && print <= 126)
		return (1);
	return (0);
}
