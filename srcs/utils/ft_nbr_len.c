/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:41:58 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/24 18:24:27 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_nbr_len(intmax_t n)
{
	int size;

	size = (n < 1) ? 1 : 0;
	while (n)
	{
		n /= 10;
		++size;
	}
	return (size);
}