/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_clink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:59:39 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/24 18:09:51 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	void	put_color(t_ls *ls)
{
	if (ls->opt & G_FLAG)
		ls_push(ls, "\e[97m");
}

void			print_clink(t_ls *ls, int number, int size)
{
	int		max;
	int		slen;

	put_color(ls);
	max = size;
	slen = ft_nbr_len(number);
	while (max - slen > 0)
	{
		ls_pushchr(ls, ' ');
		--max;
	}
	ls_push_nbr(ls, number);
}
