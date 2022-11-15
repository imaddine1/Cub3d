/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:59:10 by iharile           #+#    #+#             */
/*   Updated: 2021/11/22 10:55:37 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	unsigned char	alpha;

	alpha = (unsigned char)c;
	if ((alpha >= 'a' && alpha <= 'z') || (alpha >= 'A' && alpha <= 'Z'))
		return (1);
	return (0);
}
