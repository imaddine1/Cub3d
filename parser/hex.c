/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:18:31 by iharile           #+#    #+#             */
/*   Updated: 2022/11/01 20:00:09 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	hex(int *arr)
{
	int	k;

	k = arr[0] << 16;
	k += arr[1] << 8;
	k += arr[2];
	return (k);
}
