/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:00:20 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/25 10:10:13 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_size(t_ls *ls, int number, int size)
{
	int		max;
	int		slen;

	max = size;
	slen = ft_nbr_len(number);
	while (max - slen > 0)
	{
		ls_pushchr(ls, ' ');
		--max;
	}
	ls_push_nbr(ls, number);
}
