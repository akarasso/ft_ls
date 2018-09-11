/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_min_maj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:57:26 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/24 18:12:21 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_min_maj(t_ls *ls, t_lst_file *file)
{
	int major;
	int minor;
	int nlen;
	int max;

	major = file->data.stat.st_rdev;
	minor = file->data.stat.st_rdev % 256;
	while (major / 256 > 0)
		major /= 256;
	nlen = ft_nbr_len(major);
	max = 5;
	while (--max - nlen > -1)
		ls_pushchr(ls, ' ');
	ls_push_nbr(ls, major);
	ls_push(ls, ",");
	nlen = ft_nbr_len(minor);
	max = 4;
	while (max - nlen > 0)
	{
		ls_pushchr(ls, ' ');
		--max;
	}
	ls_push_nbr(ls, minor);
}
